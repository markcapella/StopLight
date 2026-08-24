
// Class header.
#include "ConfigDialog.h"

// App headers.
#include "AboutDialog.h"
#include "ComboboxDelegate.h"
#include "MinutesHints.h"
#include "PercentageHints.h"
#include "TranslationHelper.h"
#include "TranslationHelperStrings.h"
#include "ui_ConfigDialog.h"

// C Headers.
#include <cstdio>
#include <iostream>

// Qt Headers.
#include <QCheckBox>
#include <QComboBox>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>

// LXQT Headers.
#include <lxqt/pluginsettings.h>

/**
 *
 */
ConfigDialog::ConfigDialog(StopLight* stopLight,
    PluginSettings* settings, QWidget* parent) : QDialog(parent),
    ui(new Ui::ConfigDialog), mSettings(settings) {
    cout << "ConfigDialog CONSTRUCTOR() Starts." << endl;

    mStopLight = stopLight;

    setWindowFlags(Qt::Dialog | Qt::Tool);
    resize(CONFIG_DIALOG_WIDTH, CONFIG_DIALOG_HEIGHT);
    setFixedSize(size());

    // Setup window title.
    QString TITLE = mSettings->group() + " " + gTranslationHelper->
        getTranslationOf("Configuration", getStringSetting(APP_LANGUAGE));
    setWindowTitle(QString(TITLE));
    setWindowIcon(QIcon::fromTheme(ICON_NAME));

    // Set the window attributes, create controls & center.
    ui->setupUi(this);
    mMainLayout = ui->mMainLayout;
    mFormLayout = ui->mFormLayout;
    createConfigDialog();

    // Create Buttons Layout, & create all buttons.
    mResetButton = new QPushButton("Reset", this);
    mAboutButton = new QPushButton("About", this);
    mOkButton = new QPushButton("Ok", this);
    mApplyButton = new QPushButton("Apply", this);
    mCancelButton = new QPushButton("Cancel", this);

    // Ensure nothing defaults to having focus.
    mResetButton->setAutoDefault(false);
    mAboutButton->setAutoDefault(false);
    mOkButton->setAutoDefault(false);
    mApplyButton->setAutoDefault(false);
    mCancelButton->setAutoDefault(false);

    const bool SHOULD_DISPLAY_ICONS = getBoolSetting(ICONS_ON_BUTTONS);
    if (SHOULD_DISPLAY_ICONS) {
        mResetButton->setIcon(QIcon::fromTheme("edit-undo"));
        mAboutButton->setIcon(QIcon::fromTheme("help-about"));
        mOkButton->setIcon(QIcon::fromTheme("dialog-ok"));
        mApplyButton->setIcon(QIcon::fromTheme("dialog-ok-apply"));
        mCancelButton->setIcon(QIcon::fromTheme("dialog-cancel"));
    } else {
        mResetButton->setIcon(QIcon());
        mAboutButton->setIcon(QIcon());
        mOkButton->setIcon(QIcon());
        mApplyButton->setIcon(QIcon());
        mCancelButton->setIcon(QIcon());
    }

    // Add all buttons to the layout.
    mButtonLayout = new QHBoxLayout();
    mButtonLayout->addWidget(mResetButton);
    mButtonLayout->addWidget(mAboutButton);
    mButtonLayout->addStretch();
    mButtonLayout->addWidget(mOkButton);
    mButtonLayout->addWidget(mApplyButton);
    mButtonLayout->addWidget(mCancelButton);

    // Add buttons widget to layout & set as Layout.
    mMainLayout->addLayout(mButtonLayout);

    // Connect all button click signals.
    connect(mResetButton, &QPushButton::clicked, this,
        &ConfigDialog::resetConfigDialog);
    connect(mAboutButton, &QPushButton::clicked, this,
        &ConfigDialog::showAboutDialog);

    connect(mOkButton, &QPushButton::clicked, this,
        &ConfigDialog::okConfigDialog);
    connect(mApplyButton, &QPushButton::clicked, this,
        &ConfigDialog::acceptConfigDialog);
    connect(mCancelButton, &QPushButton::clicked, this,
        &ConfigDialog::cancelConfigDialog);

    // Init settings change list, size / value.
    mSettingChanges.fill(false, PROPERTIES.size());

    cout << "ConfigDialog CONSTRUCTOR() Finishes." << endl;
}

/**
 *
 */
ConfigDialog::~ConfigDialog() {
    delete ui;
}

/**
 *
 */
void
ConfigDialog::showEvent(QShowEvent* event) {
    cout << "showEvent() Starts." << endl;

    loadConfigDialog();
    mSettingChanges.fill(false);
    mApplyButton->setEnabled(false);

    QDialog::showEvent(event);
    cout << "showEvent() Finishes." << endl;
}

/**
 * Create dialog with settings names & widgets.
 */
void
ConfigDialog::createConfigDialog() {
    cout << "createConfigDialog() Starts." << endl;

    const int SETTINGS_SIZE = PROPERTIES.size();
    for (int i = 0; i < SETTINGS_SIZE; i++) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        const QString THIS_KEY = THIS_SETTING.name;
        const SettingsPropertyType THIS_VALUETYPE =
            THIS_SETTING.valueType;
        const QString I18N_DISPLAY_KEY = gTranslationHelper->
            getTranslationOf(THIS_KEY, getStringSetting(APP_LANGUAGE));

        // Get QCheckBox for Booleans.
        if (THIS_VALUETYPE == BOOL_VALUETYPE) {
            QCheckBox* checkboxWidget = new QCheckBox(this);
            checkboxWidget->setObjectName(THIS_KEY);
            mFormLayout->addRow(I18N_DISPLAY_KEY, checkboxWidget);
            connect(checkboxWidget, &QCheckBox::toggled,
                this, [this, i] (bool checked) { Q_UNUSED(checked);
                mSettingChanges[i] = true;
                mApplyButton->setEnabled(true);
            });
            continue;
        }

        // Get QLineEdit for Divider lines.
        if (THIS_VALUETYPE == DIVIDER_VALUETYPE) {
            QLabel* dividerWidget = new QLabel(this);
            dividerWidget->setObjectName(THIS_KEY);
            const int SLIDER_HEIGHT_VALUE = getIntSetting(THIS_KEY);
            dividerWidget->setFixedHeight(SLIDER_HEIGHT_VALUE);
            mFormLayout->addRow("", dividerWidget);
            continue;
        }

        // Get QlineEdit for Ints.
        if (THIS_VALUETYPE == INT_VALUETYPE) {
            QLineEdit* lineEditWidget = new QLineEdit(this);
            lineEditWidget->setObjectName(THIS_KEY);
            lineEditWidget->setFixedWidth(120);
            mFormLayout->addRow(I18N_DISPLAY_KEY, lineEditWidget);
            connect(lineEditWidget, &QLineEdit::textChanged,
                this, [this, i] (const QString &text) { Q_UNUSED(text);
                mSettingChanges[i] = true;
                mApplyButton->setEnabled(true);
            }); 
            continue;
        }

        // Get QComboBox for choices.
        if (THIS_VALUETYPE == COMBOBOX_VALUETYPE &&
            THIS_KEY == APP_LANGUAGE) {
            QComboBox* langComboWidget = new QComboBox(this);
            langComboWidget->setItemDelegate(new ComboboxDelegate(
                langComboWidget));
            langComboWidget->addItems(ALL_LANGUAGES);
            langComboWidget->setObjectName(THIS_KEY);
            mFormLayout->addRow(I18N_DISPLAY_KEY, langComboWidget);
            connect(langComboWidget,&QComboBox::currentIndexChanged,
                this, [this, i] (int index) { Q_UNUSED(index);
                mSettingChanges[i] = true;
                mApplyButton->setEnabled(true);
            });
            continue;
        }

        // Get QSliders.
        if (THIS_VALUETYPE == SLIDER_VALUETYPE) {
            QSlider* sliderEditWidget = new QSlider(Qt::Horizontal, this);
            sliderEditWidget->setObjectName(THIS_KEY);
            sliderEditWidget->setFixedWidth(160);
            mFormLayout->addRow(I18N_DISPLAY_KEY, sliderEditWidget);

            // Nice tooltip on slow hover of PCT hints.
            if (THIS_KEY == INDICATOR_MARGIN_SIZE ||
                THIS_KEY == INDICATOR_SIZE ||
                THIS_KEY == INDICATOR_TEXT_SIZE) {
                connect(sliderEditWidget, &QSlider::valueChanged,
                    this, [this, i, sliderEditWidget] (int value) {
                    const QString TOOLTIP_TEXT = QString::number(value) + "%";
                    QToolTip::showText(QCursor::pos(), TOOLTIP_TEXT,
                        sliderEditWidget);
                    mSettingChanges[i] = true;
                    mApplyButton->setEnabled(true);
                });
                sliderEditWidget->installEventFilter(
                    new PercentageHints(sliderEditWidget));
                continue;
            }

            // Nice tooltip on slow hover.
            if (THIS_KEY == YELLOW_INDICATOR_THRESHOLD) {
                connect(sliderEditWidget, &QSlider::valueChanged,
                    this, [this, i, sliderEditWidget] (int value) {
                    const QString TOOLTIP_TEXT = QString::number(value) + "%";
                    QToolTip::showText(QCursor::pos(), TOOLTIP_TEXT,
                        sliderEditWidget);
                    mSettingChanges[i] = true;
                    mApplyButton->setEnabled(true);

                    QSlider* RED_WIDGET = findChild<QSlider*>
                        (RED_INDICATOR_THRESHOLD);
                    if (value < RED_WIDGET->sliderPosition()) {
                        RED_WIDGET->setSliderPosition(value);
                    }
                });
                sliderEditWidget->installEventFilter(
                    new PercentageHints(sliderEditWidget));
                continue;
            }

            // Nice tooltip on slow hover.
            if (THIS_KEY == RED_INDICATOR_THRESHOLD) {
                connect(sliderEditWidget, &QSlider::valueChanged,
                    this, [this, i, sliderEditWidget] (int value) {
                    const QString TOOLTIP_TEXT = QString::number(value) + "%";
                    QToolTip::showText(QCursor::pos(), TOOLTIP_TEXT,
                        sliderEditWidget);
                    mSettingChanges[i] = true;
                    mApplyButton->setEnabled(true);

                    QSlider* YELLOW_WIDGET = findChild<QSlider*>
                        (YELLOW_INDICATOR_THRESHOLD);
                    if (value > YELLOW_WIDGET->sliderPosition()) {
                        YELLOW_WIDGET->setSliderPosition(value);
                    }
                });
                sliderEditWidget->installEventFilter(
                    new PercentageHints(sliderEditWidget));
                continue;
            }

            // Nice tooltip on slow hover of Minutes hints.
            if (THIS_KEY == INDICATOR_UPDATE_MINS) {
                connect(sliderEditWidget, &QSlider::valueChanged,
                    this, [this, i, sliderEditWidget] (int value) {
                    const QString I18N_UPDATE_TIME = (value == 1) ?
                        gTranslationHelper->getTranslationOf("minute", getStringSetting(APP_LANGUAGE)) :
                        gTranslationHelper->getTranslationOf("minutes", getStringSetting(APP_LANGUAGE));
                    const QString TOOLTIP_TEXT = QString::number(value) +
                        " " + I18N_UPDATE_TIME;
                    QToolTip::showText(QCursor::pos(), TOOLTIP_TEXT,
                        sliderEditWidget);
                    mSettingChanges[i] = true;
                    mApplyButton->setEnabled(true);
                });
                sliderEditWidget->installEventFilter(
                    new MinutesHints(this, sliderEditWidget));
                continue;
            }
        }
    }
    cout << "createConfigDialog() Finishes." << endl;
}

/**
 * Translate Settings names.
 */
void
ConfigDialog::translateConfigDialog() {
    cout << "translateConfigDialog() Starts." << endl;

    // Setup window title, 
    QString TITLE = QString(APP_NAME) + " " + gTranslationHelper->
        getTranslationOf("Configuration", getStringSetting(APP_LANGUAGE));
    setWindowTitle(QString(TITLE));

    // Translate all settings.
    const int FORM_LAYOUT_SIZE = mFormLayout->rowCount();
    for (int i = 0; i < FORM_LAYOUT_SIZE; ++i) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        const QString THIS_KEY = THIS_SETTING.name;
        const SettingsPropertyType THIS_VALUETYPE =
            THIS_SETTING.valueType;

        // Ignore Divider lines.
        if (THIS_VALUETYPE == DIVIDER_VALUETYPE) {
            continue;
        }

        const QLayoutItem* ROW = mFormLayout->itemAt(
            i, QFormLayout::LabelRole);
        if (ROW) {
            QLabel* label = qobject_cast<QLabel*>(ROW->widget());
            if (label) {
                const QString VALUE = gTranslationHelper->getTranslationOf(
                    THIS_KEY, getStringSetting(APP_LANGUAGE));
                label->setText(VALUE);
            }
        }
    }

    mResetButton->setText(gTranslationHelper->getTranslationOf("Reset",
        getStringSetting(APP_LANGUAGE)));
    mAboutButton->setText(gTranslationHelper->getTranslationOf("About",
        getStringSetting(APP_LANGUAGE)));
    mOkButton->setText(gTranslationHelper->getTranslationOf("Ok",
        getStringSetting(APP_LANGUAGE)));
    mApplyButton->setText(gTranslationHelper->getTranslationOf("Apply",
        getStringSetting(APP_LANGUAGE)));
    mCancelButton->setText(gTranslationHelper->getTranslationOf("Cancel",
        getStringSetting(APP_LANGUAGE)));

    mResetButton->clearFocus();
    mAboutButton->clearFocus();
    mOkButton->clearFocus();
    mApplyButton->clearFocus();
    mCancelButton->clearFocus();

    cout << "translateConfigDialog() Finishes." << endl;
}

/**
 * Load dialog with settings values.
 */
void
ConfigDialog::loadConfigDialog() {
    cout << "loadConfigDialog() Starts." << endl;

    const int FORM_LAYOUT_SIZE = mFormLayout->rowCount();
    for (int i = 0; i < FORM_LAYOUT_SIZE; ++i) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        const QString THIS_KEY = THIS_SETTING.name;
        const SettingsPropertyType THIS_VALUETYPE = THIS_SETTING.valueType;

        // Ignore Divider lines.
        if (THIS_VALUETYPE == DIVIDER_VALUETYPE) {
            continue;
        }

        // Get QCheckBox for Booleans.
        if (THIS_VALUETYPE == BOOL_VALUETYPE) {
            QCheckBox* checkboxWidget = nullptr;
            checkboxWidget = qobject_cast<QCheckBox*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (checkboxWidget) {
                const bool VALUE = getBoolSetting(THIS_KEY);
                checkboxWidget->setCheckState(VALUE ?
                    Qt::Checked : Qt::Unchecked);
            }
            continue;
        }

        // Get QlineEdit for Ints.
        if (THIS_VALUETYPE == INT_VALUETYPE) {
            QLineEdit* lineEditWidget = nullptr;
            lineEditWidget = qobject_cast<QLineEdit*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (lineEditWidget) {
                const int VALUE = getIntSetting(THIS_KEY);
                lineEditWidget->setText(QString::number(VALUE));
            }
            continue;
        }

        // Get QComboBox for Choices.
        if (THIS_VALUETYPE == COMBOBOX_VALUETYPE) {
            QComboBox* langComboWidget = nullptr;
            langComboWidget = qobject_cast<QComboBox*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (langComboWidget) {
                const QString LANG = getStringSetting(THIS_KEY);
                const int LANG_INDEX = ALL_LANGUAGES.indexOf(LANG);
                langComboWidget->setCurrentIndex(LANG_INDEX);
            }
            continue;
        }

        // Get QSliders.
        if (THIS_VALUETYPE == SLIDER_VALUETYPE) {
            QSlider* sliderEditWidget = nullptr;
            sliderEditWidget = qobject_cast<QSlider*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (sliderEditWidget) {
                sliderEditWidget->setMinimum(getSettingsIntRangeMinimum(
                    THIS_KEY));
                sliderEditWidget->setMaximum(getSettingsIntRangeMaximum(
                    THIS_KEY));
                const int VALUE = getIntSetting(THIS_KEY);
                sliderEditWidget->setSliderPosition(VALUE);
            }
            continue;
        }
    }

    cout << "loadConfigDialog() Finishes." << endl;
}

/**
 * Load dialog with DEFAULT settings values.
 */
void
ConfigDialog::loadConfigDialogWithDefaults() {
    cout << "loadConfigDialog() Starts." << endl;

    const int FORM_LAYOUT_SIZE = mFormLayout->rowCount();
    for (int i = 0; i < FORM_LAYOUT_SIZE; ++i) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        const QString THIS_KEY = THIS_SETTING.name;
        const SettingsPropertyType THIS_VALUETYPE = THIS_SETTING.valueType;

        // Ignore Divider lines.
        if (THIS_VALUETYPE == DIVIDER_VALUETYPE) {
            continue;
        }

        // Get QCheckBox for Booleans.
        if (THIS_VALUETYPE == BOOL_VALUETYPE) {
            QCheckBox* checkboxWidget = nullptr;
            checkboxWidget = qobject_cast<QCheckBox*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (checkboxWidget) {
                const bool VALUE = getSettingsDefaultBoolValue(THIS_KEY);
                checkboxWidget->setCheckState(VALUE ?
                    Qt::Checked : Qt::Unchecked);
            }
            continue;
        }

        // Get QlineEdit for Ints.
        if (THIS_VALUETYPE == INT_VALUETYPE) {
            QLineEdit* lineEditWidget = nullptr;
            lineEditWidget = qobject_cast<QLineEdit*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (lineEditWidget) {
                const int VALUE = getSettingsDefaultIntValue(THIS_KEY);
                lineEditWidget->setText(QString::number(VALUE));
            }
            continue;
        }

        // Get QComboBox for Choices.
        if (THIS_VALUETYPE == COMBOBOX_VALUETYPE) {
            // Don't reset language to default.
            if (THIS_KEY == APP_LANGUAGE) {
                continue;
            }
            QComboBox* langComboWidget = nullptr;
            langComboWidget = qobject_cast<QComboBox*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (langComboWidget) {
                const QString LANG = getSettingsDefaultStringValue(THIS_KEY);
                const int LANG_INDEX = ALL_LANGUAGES.indexOf(LANG);
                langComboWidget->setCurrentIndex(LANG_INDEX);
            }
            continue;
        }

        // Get QSliders.
        if (THIS_VALUETYPE == SLIDER_VALUETYPE) {
            QSlider* sliderEditWidget = nullptr;
            sliderEditWidget = qobject_cast<QSlider*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (sliderEditWidget) {
                sliderEditWidget->setMinimum(getSettingsIntRangeMinimum(
                    THIS_KEY));
                sliderEditWidget->setMaximum(getSettingsIntRangeMaximum(
                    THIS_KEY));
                const int VALUE = getSettingsDefaultIntValue(THIS_KEY);
                sliderEditWidget->setSliderPosition(VALUE);
            }
            continue;
        }
    }

    cout << "loadConfigDialog() Finishes." << endl;
}

/**
 * Update any runtime dialog controls, range settings, etc.
 */
void
ConfigDialog::updateConfigDialog() {
    cout << "updateConfigDialog() Starts." << endl;
    cout << "updateConfigDialog() Finishes." << endl;
}

/**
 * Accept & apply settings, close dialog.
 */
void
ConfigDialog::okConfigDialog() {
    cout << "okConfigDialog() Starts." << endl;
    acceptConfigDialog();

    // Finish "Ok".
    accept();
    cout << "okConfigDialog() Finishes." << endl;
}

/**
 * Accept & apply settings, stay in dialog.
 */
void
ConfigDialog::acceptConfigDialog() {
    cout << "acceptConfigDialog() Starts." << endl;

    const int FORM_LAYOUT_SIZE = mFormLayout->rowCount();
    for (int i = 0; i < FORM_LAYOUT_SIZE; ++i) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        const QString THIS_KEY = THIS_SETTING.name;
        const SettingsPropertyType THIS_VALUETYPE = THIS_SETTING.valueType;

        // Ignore Divider lines.
        if (THIS_VALUETYPE == DIVIDER_VALUETYPE) {
            continue;
        }

        // Get QCheckBox for Booleans.
        if (THIS_VALUETYPE == BOOL_VALUETYPE) {
            QCheckBox* checkboxWidget = nullptr;
            checkboxWidget = qobject_cast<QCheckBox*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (checkboxWidget) {
                const bool VALUE = checkboxWidget->checkState();
                setBoolSetting(THIS_KEY, VALUE);
            }
            continue;
        }

        // Get QlineEdit for Ints.
        if (THIS_VALUETYPE == INT_VALUETYPE) {
            QLineEdit* lineEditWidget = nullptr;
            lineEditWidget = qobject_cast<QLineEdit*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (lineEditWidget) {
                const int VALUE = lineEditWidget->text().toInt();
                setIntSetting(THIS_KEY, VALUE);
            }
            continue;
        }

        // Get QComboBox for Choices.
        if (THIS_VALUETYPE == COMBOBOX_VALUETYPE &&
            THIS_KEY == APP_LANGUAGE) {
            QComboBox* langComboWidget = nullptr;
            langComboWidget = qobject_cast<QComboBox*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (langComboWidget) {
                const QString VALUE = langComboWidget->currentText();
                setStringSetting(THIS_KEY, VALUE);
            }
            continue;
        }


        // Get QSliders.
        if (THIS_VALUETYPE == SLIDER_VALUETYPE) {
            QSlider* sliderEditWidget = nullptr;
            sliderEditWidget = qobject_cast<QSlider*>(mFormLayout->
                itemAt(i, QFormLayout::FieldRole)->widget());
            if (sliderEditWidget) {
                const int VALUE = sliderEditWidget->value();
                setIntSetting(THIS_KEY, VALUE);
            }
            continue;
        }
    }

    // Translate controls to new lang for next time.
    translateConfigDialog();

    // Redraw the StopLightView on ConfigDialog updates.
    // Update the view timer with maybe new ConfigDialog value.
    // Update the plugin view with maybe new size.
    gStopLightView->updateTimerInterval();
    gStopLightView->setPluginWidth();
    gStopLightView->update();

    mSettingChanges.fill(false);
    mApplyButton->setEnabled(false);

    const bool SHOULD_DISPLAY_ICONS = getBoolSetting(ICONS_ON_BUTTONS);
    if (SHOULD_DISPLAY_ICONS) {
        mResetButton->setIcon(QIcon::fromTheme("edit-undo"));
        mAboutButton->setIcon(QIcon::fromTheme("help-about"));
        mOkButton->setIcon(QIcon::fromTheme("dialog-ok"));
        mApplyButton->setIcon(QIcon::fromTheme("dialog-ok-apply"));
        mCancelButton->setIcon(QIcon::fromTheme("dialog-cancel"));
    } else {
        mResetButton->setIcon(QIcon());
        mAboutButton->setIcon(QIcon());
        mOkButton->setIcon(QIcon());
        mApplyButton->setIcon(QIcon());
        mCancelButton->setIcon(QIcon());
    }

    cout << "acceptConfigDialog() Finishes." << endl;
}

/**
 * Call Qt6 to accept & close the dialog.
 */
void
ConfigDialog::accept() {
    cout << "accept() Starts." << endl;
    QDialog::accept();
    cout << "accept() Finishes." << endl;
}

/**
 * Call Qt6 to cancel & close the dialog.
 */
void
ConfigDialog::cancelConfigDialog() {
    cout << "cancelConfigDialog() Starts." << endl;
    QDialog::reject();
    cout << "cancelConfigDialog() Finishes." << endl;
}

/**
 * Reset all settings values to default.
 */
void
ConfigDialog::resetConfigDialog() {
    cout << "resetConfigDialog() Starts." << endl;

    loadConfigDialogWithDefaults();
    mSettingChanges.fill(true);
    mApplyButton->setEnabled(true);

    cout << "resetConfigDialog() Finishes." << endl;
}

/**
 * Show this apps "About" dialog.
 */
void
ConfigDialog::showAboutDialog() {
    cout << "showAboutDialog() Starts." << endl;

    mAboutDialog = new AboutDialog(mSettings, this);
    mAboutDialog->show();

    cout << "showAboutDialog() Finishes." << endl;
}

/**
 * Getter for user configurable bool settings.
 */
bool
ConfigDialog::getBoolSetting(const QString setting) {
    const bool RESULT = mSettings->value(setting,
        getSettingsDefaultStringValue(setting)).toBool();
    return RESULT;
}

/**
 * Getter for user configurable int settings.
 */
int
ConfigDialog::getIntSetting(const QString setting) {
    const int RESULT = mSettings->value(setting,
        getSettingsDefaultStringValue(setting)).toInt();
    return RESULT;
}

/**
 * Getter for user configurable string settings.
 */
QString
ConfigDialog::getStringSetting(const QString setting) {
    const QString RESULT = mSettings->value(setting,
        getSettingsDefaultStringValue(setting)).toString();
    return RESULT;
}

/**
 * Setter for user configurable bool settings.
 */
void
ConfigDialog::setBoolSetting(const QString setting,
    const bool value) {
    mSettings->setValue(setting, value);
}

/**
 * Setter for user configurable int settings.
 */
void
ConfigDialog::setIntSetting(const QString setting,
    const int value) {
    mSettings->setValue(setting, value);
}

/**
 * Setter for user configurable string settings.
 */
void
ConfigDialog::setStringSetting(const QString setting,
    const QString value) {
    mSettings->setValue(setting, value);
}

/**
 * Return the value type of a Setting by key.
 */
ConfigDialog::SettingsPropertyType
ConfigDialog::getSettingsValueType(const QString key) {
    const int SETTINGS_SIZE = PROPERTIES.size();

    for (int i = 0; i < SETTINGS_SIZE; i++) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        if (key == THIS_SETTING.name) {
            return THIS_SETTING.valueType;
        }
    }
    return NONE_VALUETYPE;
}

/**
 * Return the default value of a bool Setting by key.
 */
bool
ConfigDialog::getSettingsDefaultBoolValue(const QString key) {
    bool resultValue = false;

    const int SETTINGS_SIZE = PROPERTIES.size();
    for (int i = 0; i < SETTINGS_SIZE; i++) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        if (key == THIS_SETTING.name) {
            resultValue = (THIS_SETTING.initialValue ==
                QString("true").toLower());
            break;
        }
    }
    return resultValue;
}

/**
 * Return the default value of an int Setting by key.
 */
int
ConfigDialog::getSettingsDefaultIntValue(const QString key) {
    int resultValue = 0;

    const int SETTINGS_SIZE = PROPERTIES.size();
    for (int i = 0; i < SETTINGS_SIZE; i++) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        if (key == THIS_SETTING.name) {
            resultValue = THIS_SETTING.initialValue.toInt();
            break;
        }
    }
    return resultValue;
}

/**
 * Return the default value of a Setting by key.
 */
QString
ConfigDialog::getSettingsDefaultStringValue(const QString key) {
    QString resultValue = "";

    const int SETTINGS_SIZE = PROPERTIES.size();
    for (int i = 0; i < SETTINGS_SIZE; i++) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        if (key == THIS_SETTING.name) {
            resultValue = THIS_SETTING.initialValue;
            break;
        }
    }
    return resultValue;
}

/**
 * Get a Minimum int value to load a UI widget.
 */
int
ConfigDialog::getSettingsIntRangeMinimum(const QString key) {
    int resultValue = numeric_limits<int>::min();
    const int SETTINGS_SIZE = PROPERTIES.size();

    for (int i = 0; i < SETTINGS_SIZE; i++) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        if (key == THIS_SETTING.name) {
            resultValue = THIS_SETTING.rangeMinimum;
            break;
        }
    }
    return resultValue;
}

/**
 * Get a Maximum int value to load a UI widget.
 */
int
ConfigDialog::getSettingsIntRangeMaximum(const QString key) {
    int resultValue = numeric_limits<int>::max();
    const int SETTINGS_SIZE = PROPERTIES.size();

    for (int i = 0; i < SETTINGS_SIZE; i++) {
        const SettingsProperty THIS_SETTING = PROPERTIES[i];
        if (key == THIS_SETTING.name) {
            resultValue = THIS_SETTING.rangeMaximum;
            break;
        }
    }
    return resultValue;
}

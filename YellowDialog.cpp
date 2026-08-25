
// App headers.
#include "Globals.h"
#include "YellowDialog.h"

#include "ConfigDialog.h"
#include "TranslationHelper.h"

// C Headers.
#include <iostream>
using namespace std;

// Qt Headers.
#include <QDesktopServices>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

// LXQT Headers.
#include <lxqt/pluginsettings.h>

/**
 * Simple class to represent an YellowDialog.
 *
 */
YellowDialog::YellowDialog(PluginSettings* settings,
    QWidget* parent) : QDialog(parent) {

    // Save App ref.
    mSettings = settings;

    // Set window flags & resize.
    setWindowFlags(Qt::Dialog | Qt::Tool);
    resize(CONFIG_DIALOG_WIDTH, CONFIG_DIALOG_HEIGHT);
    setFixedSize(size());

    // Set title & icon.
    const QString LANGUAGE_FOR_I18N = gConfigDialog->
        getStringSetting(ConfigDialog::APP_LANGUAGE);
    const QString YELLOW_TITLE_I18N = gTranslationHelper->
        getTranslationOf(YELLOW_TITLE, LANGUAGE_FOR_I18N);
    setWindowTitle(mSettings->group() + " " + YELLOW_TITLE_I18N);
    setWindowIcon(QIcon::fromTheme(APP_ICON));

    // Create overall container.
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->addSpacing(20);

    const QString YELLOW_WARNING_I18N = "🟡 " + gTranslationHelper->
        getTranslationOf(YELLOW_WARNING, LANGUAGE_FOR_I18N);
    QLabel* appTitleLine = new QLabel(YELLOW_WARNING_I18N);

    appTitleLine->setAlignment(Qt::AlignCenter);
    appTitleLine->setWordWrap(true);
    QFont appTitleFont = appTitleLine->font();
    appTitleFont.setPointSize(FONT_BASE_SIZE);
    appTitleFont.setBold(true);
    appTitleFont.setItalic(true);
    appTitleLine->setFont(appTitleFont);
    mainLayout->addWidget(appTitleLine);

    // Add blank line before Buttons Box.
    mainLayout->addSpacing(20);

    // Create Ok ButtonBoxBox.
    const bool SHOULD_DISPLAY_ICONS = gConfigDialog->
        getBoolSetting(ConfigDialog::SHOW_ICONS_ON_BUTTONS);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok, this);
    QPushButton* okButton = buttonBox->button(QDialogButtonBox::Ok);
    okButton->setText(gTranslationHelper->getTranslationOf("Ok",
        gConfigDialog->getStringSetting(ConfigDialog::
            APP_LANGUAGE)));
    if (SHOULD_DISPLAY_ICONS) {
        okButton->setIcon(QIcon::fromTheme("dialog-ok"));
    } else {
        okButton->setIcon(QIcon());
    }

    // Connect Ok and Repo signals.
    connect(buttonBox, &QDialogButtonBox::accepted, this,
        &QDialog::accept);

    mainLayout->addWidget(buttonBox);
}

/**
 * Destructor.
 */
YellowDialog::~YellowDialog() {
    delete gTranslationHelper;
}

/**
 * Close the YellowDialog when the window is closed
 * by clicking top-right 'X' button.
 *
 * Accept the close event so the system knows we handled
 * the window destruction.
 */
void
YellowDialog::closeEvent(QCloseEvent* event) {
    reject();

    event->accept();
}

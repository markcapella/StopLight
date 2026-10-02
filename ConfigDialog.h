
#pragma once

// App Class forwards.
class StopLight;

// App ui interface.
namespace Ui {
    class ConfigDialog;
}

// C Headers.
#include <vector>

// Qt Headers.
#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

// LXQT forward decls.
class PluginSettings;

/**
 * StopLight configuration dialog.
 */
class ConfigDialog : public QDialog {
    Q_OBJECT

    public:
        static inline const int CONFIG_DIALOG_WIDTH = 650;
        static inline const int CONFIG_DIALOG_HEIGHT = 750;

        // Configurable Settings strings.
        static inline const QString SHOW_GREEN_INDICATOR          = QString(QT_TR_NOOP("🟢 Show Green Indicator"));
        static inline const QString SHOW_GREEN_TEXT               = QString(QT_TR_NOOP("Show Green Indicator Text"));
        static inline const QString DIVIDER_0 = "00";

        static inline const QString SHOW_YELLOW_INDICATOR         = QString(QT_TR_NOOP("🟡 Show Yellow Indicator"));
        static inline const QString SHOW_YELLOW_AT_THRESHOLD      = QString(QT_TR_NOOP("Show Yellow Indicator When"));
        static inline const QString SHOW_YELLOW_TEXT              = QString(QT_TR_NOOP("Show Yellow Indicator Text"));
        static inline const QString SHOW_YELLOW_DIALOG            = QString(QT_TR_NOOP("Show Yellow Indicator Dialog"));
        static inline const QString DIVIDER_1 = "01";

        static inline const QString SHOW_RED_INDICATOR            = QString(QT_TR_NOOP("🔴 Show Red Indicator"));
        static inline const QString SHOW_RED_AT_THRESHOLD         = QString(QT_TR_NOOP("Show Red Indicator When"));
        static inline const QString SHOW_RED_TEXT                 = QString(QT_TR_NOOP("Show Red Indicator Text"));
        static inline const QString SHOW_RED_DIALOG               = QString(QT_TR_NOOP("Show Red Indicator Dialog"));
        static inline const QString DIVIDER_2 = "02";

        static inline const QString SHOW_TEXT_INDICATOR           = QString(QT_TR_NOOP("Show Text Indicator"));
        static inline const QString SHOW_ICON_INDICATOR           = QString(QT_TR_NOOP("Show Icon when no Indicators"));
        static inline const QString INDICATOR_UPDATE_MINS         = QString(QT_TR_NOOP("Time between Indicator Updates"));
        static inline const QString DIVIDER_3 = "03";

        static inline const QString INDICATOR_MARGIN_SIZE         = QString(QT_TR_NOOP("Indicator Margin Size"));
        static inline const QString INDICATOR_SHRINKS_TO_ROW      = QString(QT_TR_NOOP("Indicator Shrinks to Row Height"));
        static inline const QString INDICATOR_SIZE                = QString(QT_TR_NOOP("Indicator Size"));
        static inline const QString INDICATOR_TEXT_SIZE           = QString(QT_TR_NOOP("Indicator Text Size"));
        static inline const QString DIVIDER_4 = "04";

        static inline const QString SHOW_SETTINGS_HINTS           = QString(QT_TR_NOOP("Show Settings Hints"));
        static inline const QString SHOW_ICONS_ON_BUTTONS         = QString(QT_TR_NOOP("Show Icons on Buttons"));

        // Configurable Settings hint strings.
        static inline const QString SHOW_GREEN_INDICATOR_HINT     = QString(QT_TR_NOOP("Enables or disables display of the round green indicator."));
        static inline const QString SHOW_GREEN_TEXT_HINT          = QString(QT_TR_NOOP("Enables or disables display of the space level text in the round green indicator."));

        static inline const QString SHOW_YELLOW_INDICATOR_HINT    = QString(QT_TR_NOOP("Enables or disables display of the round yellow indicator."));
        static inline const QString SHOW_YELLOW_AT_THRESHOLD_HINT = QString(QT_TR_NOOP("Sets the threshold for the yellow warning indicator to come on."));
        static inline const QString SHOW_YELLOW_TEXT_HINT         = QString(QT_TR_NOOP("Enables or disables display of the space level text in the round yellow indicator."));
        static inline const QString SHOW_YELLOW_DIALOG_HINT       = QString(QT_TR_NOOP("Enables or disables display of the yellow warning dialog."));

        static inline const QString SHOW_RED_INDICATOR_HINT       = QString(QT_TR_NOOP("Enables or disables display of the round red indicator."));
        static inline const QString SHOW_RED_AT_THRESHOLD_HINT    = QString(QT_TR_NOOP("Sets the threshold for the red error indicator to come on."));
        static inline const QString SHOW_RED_TEXT_HINT            = QString(QT_TR_NOOP("Enables or disables display of the space level text in the round red indicator."));
        static inline const QString SHOW_RED_DIALOG_HINT          = QString(QT_TR_NOOP("Enables or disables display of the red warning dialog."));

        static inline const QString SHOW_TEXT_INDICATOR_HINT      = QString(QT_TR_NOOP("Enables or disables display of the space level text."));
        static inline const QString SHOW_ICON_INDICATOR_HINT      = QString(QT_TR_NOOP("Enables or disables display of the widget icon when no indicator is otherwise displayed."));
        static inline const QString INDICATOR_UPDATE_MINS_HINT    = QString(QT_TR_NOOP("Sets duration between low space indicators and warnings checks."));

        static inline const QString INDICATOR_MARGIN_SIZE_HINT    = QString(QT_TR_NOOP("Sets left and right margin width of indicator in the panel."));
        static inline const QString INDICATOR_SHRINKS_TO_ROW_HINT = QString(QT_TR_NOOP("Allows indicator to shrink from full panel height to grouped row height."));
        static inline const QString INDICATOR_SIZE_HINT           = QString(QT_TR_NOOP("Sets indicator full size, or some percentage smaller."));
        static inline const QString INDICATOR_TEXT_SIZE_HINT      = QString(QT_TR_NOOP("Sets indicator text fullsize, or some percentage smaller."));

        static inline const QString SHOW_SETTINGS_HINTS_HINT      = QString(QT_TR_NOOP("Enables or disables display of these descriptions of settings on mouse hover."));
        static inline const QString SHOW_ICONS_ON_BUTTONS_HINT    = QString(QT_TR_NOOP("Enables or disables display of visual icons on buttons."));


        // Settings property structs.
        enum SettingsPropertyType {
            NONE_VALUETYPE,
            STRING_VALUETYPE,
            INT_VALUETYPE,
            BOOL_VALUETYPE,
            COLOR_VALUETYPE,
            SLIDER_VALUETYPE,
            DIVIDER_VALUETYPE,
            COMBOBOX_VALUETYPE
        };

        struct SettingsProperty {
            QString name = "";
            QString hint = "";
            SettingsPropertyType valueType = NONE_VALUETYPE;
            QString initialValue = "";
            int rangeMinimum = std::numeric_limits<int>::min();
            int rangeMaximum = std::numeric_limits<int>::max();
        };

        // App configurables.
        static inline const std::vector<SettingsProperty> PROPERTIES = {
            { .name = SHOW_GREEN_INDICATOR, .hint = SHOW_GREEN_INDICATOR_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_GREEN_TEXT, .hint = SHOW_GREEN_TEXT_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },

            { .name = DIVIDER_0, .hint = "",
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_YELLOW_INDICATOR, .hint = SHOW_YELLOW_INDICATOR_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_YELLOW_AT_THRESHOLD, .hint = SHOW_YELLOW_AT_THRESHOLD_HINT,
              .valueType = SLIDER_VALUETYPE, .initialValue = "40",
              .rangeMinimum = 0, .rangeMaximum = 100
            },
            { .name = SHOW_YELLOW_TEXT, .hint = SHOW_YELLOW_TEXT_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_YELLOW_DIALOG, .hint = SHOW_YELLOW_DIALOG_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },

            { .name = DIVIDER_1, .hint = "",
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_RED_INDICATOR, .hint = SHOW_RED_INDICATOR_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_RED_AT_THRESHOLD, .hint = SHOW_RED_AT_THRESHOLD_HINT,
              .valueType = SLIDER_VALUETYPE, .initialValue = "20",
              .rangeMinimum = 0, .rangeMaximum = 100
            },
            { .name = SHOW_RED_TEXT, .hint = SHOW_RED_TEXT_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_RED_DIALOG, .hint = SHOW_RED_DIALOG_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },

            { .name = DIVIDER_2, .hint = "",
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_TEXT_INDICATOR, .hint = SHOW_TEXT_INDICATOR_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_ICON_INDICATOR, .hint = SHOW_ICON_INDICATOR_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = INDICATOR_UPDATE_MINS, .hint = INDICATOR_UPDATE_MINS_HINT,
              .valueType = SLIDER_VALUETYPE, .initialValue = "10",
              .rangeMinimum = 1, .rangeMaximum = 60
            },

            { .name = DIVIDER_3, .hint = "",
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = INDICATOR_MARGIN_SIZE, .hint = INDICATOR_MARGIN_SIZE_HINT,
              .valueType = SLIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = 0,.rangeMaximum = 100
            },
            { .name = INDICATOR_SHRINKS_TO_ROW, .hint = INDICATOR_SHRINKS_TO_ROW_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "false",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = INDICATOR_SIZE, .hint = INDICATOR_SIZE_HINT,
              .valueType = SLIDER_VALUETYPE, .initialValue = "75",
              .rangeMinimum = 0,.rangeMaximum = 100
            },
            { .name = INDICATOR_TEXT_SIZE, .hint = INDICATOR_TEXT_SIZE_HINT,
              .valueType = SLIDER_VALUETYPE, .initialValue = "75",
              .rangeMinimum = 0,.rangeMaximum = 100
            },

            { .name = DIVIDER_4, .hint = "",
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_SETTINGS_HINTS, .hint = SHOW_SETTINGS_HINTS_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            },
            { .name = SHOW_ICONS_ON_BUTTONS, .hint = SHOW_ICONS_ON_BUTTONS_HINT,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = std::numeric_limits<int>::min(),
              .rangeMaximum = std::numeric_limits<int>::max()
            }
        };

        /**
         * Constructor.
         */
        explicit ConfigDialog(StopLight* stopLight,
            PluginSettings* settings, QWidget* parent = nullptr);

        /**
         * Destructor & cleanup.
         */
        ~ConfigDialog() override;

        /**
         * Getter for user configurable bool settings.
         */
        bool getBoolSetting(const QString setting);

        /**
         * Getter for user configurable int settings.
         */
        int getIntSetting(const QString setting);

        /**
         * Getter for user configurable string settings.
         */
        QString getStringSetting(const QString setting);

    protected:
        /**
         * Catch ShowEvent as "re-init Config Dialog"
         */
        void showEvent(QShowEvent* event) override;

    private:
        /**
         * Create dialog with settings names & widgets.
         */
        void createConfigDialog();

        /**
         * Load dialog with settings values.
         */
        void loadConfigDialog();

        /**
         * Load dialog with DEFAULT settings values.
         */
        void loadConfigDialogWithDefaults();

        /**
         * Update any runtime dialog controls, range settings, etc.
         */
        void updateConfigDialog();

        /**
         * Accept & apply settings, close dialog.
         */
        void okConfigDialog();

        /**
         * Accept & apply settings, stay in dialog.
         */
        void acceptConfigDialog();

        /**
         * Call Qt6 to accept & close the dialog.
         */
        void accept() override;

        /**
         * Call Qt6 to cancel & close the dialog.
         */
        void cancelConfigDialog();

        /**
         * Show this apps "About" dialog.
         */
        void showAboutDialog();

        /**
         * Setter for user configurable bool settings.
         */
        void setBoolSetting(const QString setting, const bool value);

        /**
         * Setter for user configurable int settings.
         */
        void setIntSetting(const QString setting, const int value);

        /**
         * Setter for user configurable string settings.
         */
        void setStringSetting(const QString setting, const QString value);

        /**
         * Return the value type of a Setting by key.
         */
        SettingsPropertyType getSettingsValueType(const QString key);

        /**
         * Return the default value of a bool Setting by key.
         */
        bool getSettingsDefaultBoolValue(const QString key);

        /**
         * Return the default value of an int Setting by key.
         */
        int getSettingsDefaultIntValue(const QString key);

        /**
         * Return the default value of a Setting by key.
         */
        QString getSettingsDefaultStringValue(const QString key);

        /**
         * Return the default value of a Setting by key.
         */
        QString getSettingsDefaultValue(const QString key);

        /**
         * Get a Minimum int value to load a UI widget.
         */
        int getSettingsIntRangeMinimum(const QString key);

        /**
         * Get a Maximum int value to load a UI widget.
         */
        int getSettingsIntRangeMaximum(const QString key);

        /**
         * Members.
         */
        StopLight* mStopLight = nullptr;

        Ui::ConfigDialog* ui;
        PluginSettings* mSettings;

        QVBoxLayout* mMainLayout = nullptr;
        QFormLayout* mFormLayout = nullptr;

        QHBoxLayout* mButtonLayout = nullptr;

        QPushButton* mResetButton = nullptr;
        QPushButton* mAboutButton = nullptr;
        QPushButton* mOkButton = nullptr;
        QPushButton* mApplyButton = nullptr;
        QPushButton* mCancelButton = nullptr;

        QList<bool> mSettingChanges;

        QDialog* mAboutDialog = nullptr;

};

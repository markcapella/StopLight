
#pragma once

// App Class forwards.
class StopLight;
class PluginSettings;
class TranslationHelper;

// App ui interface.
namespace Ui {
    class ConfigDialog;
}

// C Headers.
#include <vector>
using namespace std;

// Qt Headers.
#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

/**
 * StopLight configuration dialog.
 */
class ConfigDialog : public QDialog {
    Q_OBJECT

    public:
        static inline const int CONFIG_DIALOG_WIDTH = 625;
        static inline const int CONFIG_DIALOG_HEIGHT = 550;

        // Configurable Settings map.
        static inline const QString APP_LANGUAGE = "Language";

        static inline const QString DIVIDER_0 = "divider00";
        static inline const QString INDICATOR_MARGIN_SIZE =
            "Indicator Margin Size";
        static inline const QString INDICATOR_SIZE =
            "Indicator Size";
        static inline const QString INDICATOR_TEXT_SIZE =
            "Indicator Text Size";

        static inline const QString DIVIDER_1 = "divider01";
        static inline const QString SHOW_GREEN_INDICATOR =
            "Show Green Indicator";
        static inline const QString SHOW_YELLOW_INDICATOR =
            "Show Yellow Indicator";
        static inline const QString SHOW_RED_INDICATOR =
            "Show Red Indicator";

        static inline const QString DIVIDER_2 = "divider02";
        static inline const QString SHOW_TEXT_INDICATOR =
            "Show Text Indicator";

        static inline const QString DIVIDER_3 = "divider03";
        static inline const QString YELLOW_INDICATOR_THRESHOLD =
            "Show Yellow when";
        static inline const QString RED_INDICATOR_THRESHOLD =
            "Show Red when";

        static inline const QString DIVIDER_4 = "divider04";
        static inline const QString ICONS_ON_BUTTONS =
            "Show Icons on Buttons";

        static inline const QString DIVIDER_5 = "divider05";
        static inline const QString INDICATOR_UPDATE_MINS =
            "Time between Indicator Updates";


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
            SettingsPropertyType valueType = NONE_VALUETYPE;
            QString initialValue = "";
            int rangeMinimum = numeric_limits<int>::min();
            int rangeMaximum = numeric_limits<int>::max();
        };

        // App configurables.
        static inline const vector<SettingsProperty> PROPERTIES = {
            { .name = APP_LANGUAGE,
              .valueType = COMBOBOX_VALUETYPE, .initialValue = "en",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },

            { .name = DIVIDER_0,
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = INDICATOR_MARGIN_SIZE,
              .valueType = SLIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = 0,.rangeMaximum = 100
            },
            { .name = INDICATOR_SIZE,
              .valueType = SLIDER_VALUETYPE, .initialValue = "75",
              .rangeMinimum = 0,.rangeMaximum = 100
            },
            { .name = INDICATOR_TEXT_SIZE,
              .valueType = SLIDER_VALUETYPE, .initialValue = "75",
              .rangeMinimum = 0,.rangeMaximum = 100
            },

            { .name = DIVIDER_1,
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = SHOW_GREEN_INDICATOR,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = SHOW_YELLOW_INDICATOR,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = SHOW_RED_INDICATOR,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },

            { .name = DIVIDER_2,
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = SHOW_TEXT_INDICATOR,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },

            { .name = DIVIDER_3,
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = YELLOW_INDICATOR_THRESHOLD,
              .valueType = SLIDER_VALUETYPE, .initialValue = "40",
              .rangeMinimum = 0, .rangeMaximum = 100
            },
            { .name = RED_INDICATOR_THRESHOLD,
              .valueType = SLIDER_VALUETYPE, .initialValue = "20",
              .rangeMinimum = 0, .rangeMaximum = 100
            },

            { .name = DIVIDER_4,
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = INDICATOR_UPDATE_MINS,
              .valueType = SLIDER_VALUETYPE, .initialValue = "10",
              .rangeMinimum = 1, .rangeMaximum = 60
            },

            { .name = DIVIDER_5,
              .valueType = DIVIDER_VALUETYPE, .initialValue = "15",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
            },
            { .name = ICONS_ON_BUTTONS,
              .valueType = BOOL_VALUETYPE, .initialValue = "true",
              .rangeMinimum = numeric_limits<int>::min(),
              .rangeMaximum = numeric_limits<int>::max()
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

    signals:
        void settingsApplied();

    protected:
        void showEvent(QShowEvent* event) override;

    private:
        // Members.
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

        /**
         * Create dialog with settings names & widgets.
         */
        void createConfigDialog();

        /**
         * Translate Settings names.
         */
        void translateConfigDialog();

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
         * Reset all settings values to default.
         */
        void resetConfigDialog();

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

};

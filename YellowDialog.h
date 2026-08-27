
#pragma once

// App forward decls.
class ConfigDialog;

// Qt Headers.
#include <QCloseEvent>
#include <QDialog>

// Qt6 forward decls.
class QWidget;

// LXQT forward decls.
class PluginSettings;

/**
 * Simple class to represent an YellowDialog.
 */
class YellowDialog : public QDialog {
    Q_OBJECT

    public:
        static inline const int CONFIG_DIALOG_WIDTH = 700;
        static inline const int CONFIG_DIALOG_HEIGHT = 200;

        static inline const int FONT_BASE_SIZE = 16;

        /**
         * Constructor.
         */
        explicit YellowDialog(ConfigDialog* configDialog,
            PluginSettings* settings, QWidget* parent = nullptr);

        /**
         * Destructor & cleanup.
         */
        ~YellowDialog() override;

    protected:
        /**
         * Close the YellowDialog when the window is closed
         * by clicking top-right 'X' button.
         *
         * Accept the close event so the system knows we handled
         * the window destruction.
         */
        void closeEvent(QCloseEvent* event) override;

    private:
        // Members.
        ConfigDialog* mConfigDialog = nullptr;
        PluginSettings* mSettings;

};

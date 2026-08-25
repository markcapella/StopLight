
#pragma once

// App headers.
#include "TranslationHelper.h"

// Qt Headers.
#include <QDialog>
#include <QCloseEvent>

// Qt6 forward decls.
class QWidget;
class ConfigDialog;

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

        static inline const QString YELLOW_TITLE = "Warning";
        static inline const QString YELLOW_WARNING = "You've reached the threshold for a Yellow Warning! Check your free space and remove what you can.";

        /**
         * Constructor.
         */
        explicit YellowDialog(PluginSettings* settings,
            QWidget* parent = nullptr);

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
        PluginSettings* mSettings;

};

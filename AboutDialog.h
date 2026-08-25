
#pragma once

// App headers.
#include "TranslationHelper.h"

// App forward decls.
class ConfigDialog;

// Qt Headers.
#include <QDialog>

// Qt6 forward decls.
class QCloseEvent;
class QWidget;

// LXQT forward decls.
class PluginSettings;

/**
 * Simple class to represent an AboutDialog.
 */
class AboutDialog : public QDialog {
    Q_OBJECT

    public:
        static inline const int FONT_BASE_SIZE = 10;

        /**
         * Constructor.
         */
        explicit AboutDialog(PluginSettings* settings,
            ConfigDialog* parent = nullptr);

        /**
         * Destructor & cleanup.
         */
        ~AboutDialog() override;

    protected:
        /**
         * Close the AboutDialog when the window is closed
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

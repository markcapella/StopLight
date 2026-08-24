
#pragma once

// App forward decls.
class ConfigDialog;
class StopLightView;

// Qt6 headers.
#include <QObject>

// Qt6 forward decls.
class QDialog;
class QWidget;

// Lxqt headers.
#include <lxqt/ilxqtpanelplugin.h>

/**
 * StopLight 🚦 is an LXQT Panel plugin Widget that monitors your
 * base SSD or hard drive, and provides an indicator that reports
 * available space in Green, Yellow or Red warning colors.
 *
 * Warning levels & more are configurable.
 */
class StopLight : public QObject, public ILXQtPanelPlugin {
    Q_OBJECT

    public:
        /**
         * Constructor.
         */
        StopLight(const ILXQtPanelPluginStartupInfo &startupInfo);

        /**
         * Destructor & cleanup.
         */
        ~StopLight() override;

        /**
         * Returns the string that is used in the theme QSS file.
         */
        QString themeId() const override {
            return QStringLiteral("StopLight");
        }
        
        /**
         * Publish our StopLightView.
         */
        QWidget* widget() override;

        /**
         * Declare we are a stand-alone panel plugin item, and
         * our height is always that of panel.
         *
         * "Grouped" or "non-separate" items shrink small into
         * multi rows if the panel becomes configured that way.
         */
        bool isSeparate() const override {
            return true;
        }

        /**
         * Declare we have a ConfigDialog.
         */
        ILXQtPanelPlugin::Flags flags() const override {
            return HaveConfigDialog;
        }

        /**
         * Publish the ConfigDialog.
         */
        QDialog* configureDialog() override;

    private:
        // Members.
};

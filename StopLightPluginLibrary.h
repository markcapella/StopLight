
#pragma once

// Qt6 Headers.
#include <QObject>

// LXQt Headers.
#include <lxqt/ilxqtpanelplugin.h>

/**
 * Every plugin must have the ILXQtPanelPluginLibrary loader.
 */
class StopLightPluginLibrary : public QObject,
    public ILXQtPanelPluginLibrary {
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "lxqt.org/Panel/PluginInterface/3.0")

    Q_INTERFACES(ILXQtPanelPluginLibrary)

    public:
        /**
         * Unique instance of plugin allowing several running
         * in the panel @ the same time.
         */
        ILXQtPanelPlugin* instance(const
            ILXQtPanelPluginStartupInfo& startupInfo) const override;

        private:
            // Members.

};

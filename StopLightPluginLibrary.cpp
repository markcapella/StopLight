
// App Headers.
#include "StopLight.h"

// LXQt Headers.
#include "StopLightPluginLibrary.h"

/**
 * Unique instance of plugin allowing several running
 * in the panel @ the same time.
 */
ILXQtPanelPlugin*
StopLightPluginLibrary::instance(const
    ILXQtPanelPluginStartupInfo& startupInfo) const {

    return new StopLight(startupInfo);
}

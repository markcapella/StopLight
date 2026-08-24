
// Class header.
#include "StopLightPluginLibrary.h"

// App headers.
#include "StopLight.h"

/**
 * Unique instance of plugin allowing several running
 * in the panel @ the same time.
 */
ILXQtPanelPlugin*
StopLightPluginLibrary::instance(const
    ILXQtPanelPluginStartupInfo& startupInfo) const {

    return new StopLight(startupInfo);
}


// App Headers.
#include "ConfigDialog.h"
#include "StopLight.h"
#include "StopLightView.h"

// C Headers.
#include <iostream>

// Qt6 Headers.
#include <QDialog>

// LXQt Headers.
#include <lxqt/pluginsettings.h>


/**
 * StopLight 🚦 is an LXQT Panel plugin Widget that monitors your
 * base SSD or hard drive, and provides an indicator that reports
 * available space in Green, Yellow or Red warning colors.
 *
 * Warning levels & more are configurable.
 */
StopLight::StopLight(const ILXQtPanelPluginStartupInfo& startupInfo) :
    QObject(), ILXQtPanelPlugin(startupInfo) {

    // Global Config Dialog & settings helper.
    PluginSettings* SETTINGS = settings();
    mConfigDialog = new ConfigDialog(this, SETTINGS);

    // Global widget view.
    mStopLightView = new StopLightView(this, mConfigDialog, SETTINGS);
}

/**
 * Destructor & cleanup.
 */
StopLight::~StopLight() = default;

/**
 * Publish our StopLightView.
 */
QWidget*
StopLight::widget() {
    return mStopLightView;
}

/**
 * Declare we are a stand-alone panel plugin item, and
 * our height is always that of panel.
 *
 * "Grouped" or "non-separate" items shrink small into
 * multi rows if the panel becomes configured that way.
 */
bool
StopLight::isSeparate() const {
    const bool INDICATOR_SHRINKS_TO_ROW = mConfigDialog->
        getBoolSetting(ConfigDialog::INDICATOR_SHRINKS_TO_ROW);

    return INDICATOR_SHRINKS_TO_ROW ? false : true;
}

/**
 * Publish the ConfigDialog.
 */
QDialog*
StopLight::configureDialog() {
    return mConfigDialog;
}

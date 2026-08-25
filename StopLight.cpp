
// App headers.
#include "Globals.h"
#include "StopLight.h"

#include "ConfigDialog.h"
#include "StopLightView.h"
#include "TranslationHelper.h"

// C Headers.
#include <iostream>
using namespace std;

// Qt6 headers.
#include <QDialog>

/**
 * StopLight 🚦 is an LXQT Panel plugin Widget that monitors your
 * base SSD or hard drive, and provides an indicator that reports
 * available space in Green, Yellow or Red warning colors.
 *
 * Warning levels & more are configurable.
 */
StopLight::StopLight(const ILXQtPanelPluginStartupInfo& startupInfo) :
    QObject(), ILXQtPanelPlugin(startupInfo) {

    // Global translation helper.
    gTranslationHelper = new TranslationHelper();

    // Global Config Dialog & settings helper.
    PluginSettings* SETTINGS = settings();
    gConfigDialog = new ConfigDialog(this, SETTINGS);

    // Global widget view.
    gStopLightView = new StopLightView(this, SETTINGS);
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
    return gStopLightView;
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
    const bool INDICATOR_SHRINKS_TO_ROW = gConfigDialog->
        getBoolSetting(ConfigDialog::INDICATOR_SHRINKS_TO_ROW);

    return INDICATOR_SHRINKS_TO_ROW ? false : true;
}

/**
 * Publish the ConfigDialog.
 */
QDialog*
StopLight::configureDialog() {
    return gConfigDialog;
}

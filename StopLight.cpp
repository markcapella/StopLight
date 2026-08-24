
// App headers.
#include "Globals.h"
#include "StopLight.h"

#include "ConfigDialog.h"
#include "StopLightView.h"

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

    gConfigDialog = new ConfigDialog(this, settings());
    gStopLightView = new StopLightView(this);
    gTranslationHelper = new TranslationHelper();

    connect(gConfigDialog, &ConfigDialog::settingsApplied,
        this, [this]() {
            gStopLightView->update();
        }
    );
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
 * Publish the ConfigDialog.
 */
QDialog*
StopLight::configureDialog() {
    return gConfigDialog;
}

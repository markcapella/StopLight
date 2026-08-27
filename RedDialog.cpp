
// App Headers.
#include "ConfigDialog.h"
#include "RedDialog.h"

// C Headers.
#include <iostream>

// Qt Headers.
#include <QDesktopServices>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

// LXQt Headers.
#include <lxqt/pluginsettings.h>

/**
 * Simple class to represent an RedDialog.
 */
RedDialog::RedDialog(ConfigDialog* configDialog,
    PluginSettings* settings, QWidget* parent) : QDialog(parent) {

    // Save App ref.
    mSettings = settings;
    mConfigDialog = configDialog;

    // Set window flags & resize.
    setWindowFlags(Qt::Dialog | Qt::Tool);
    resize(CONFIG_DIALOG_WIDTH, CONFIG_DIALOG_HEIGHT);
    setFixedSize(size());

    // Set title & icon.
    const QString RED_TITLE_I18N = QString(tr("Alert"));
    setWindowTitle(mSettings->group() + " " + RED_TITLE_I18N);
    setWindowIcon(QIcon::fromTheme(APP_ICON));

    // Create overall container.
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->addSpacing(25);

    const QString RED_ALERT_I18N = "🔴 " + QString(tr("You've reached "
        "the threshold for a Red Alert! Check your free space and "
        "remove what you can."));
    QLabel* appTitleLine = new QLabel(RED_ALERT_I18N);

    appTitleLine->setAlignment(Qt::AlignCenter);
    appTitleLine->setWordWrap(true);
    QFont appTitleFont = appTitleLine->font();
    appTitleFont.setPointSize(FONT_BASE_SIZE);
    appTitleFont.setBold(true);
    appTitleFont.setItalic(true);
    appTitleLine->setFont(appTitleFont);
    mainLayout->addWidget(appTitleLine);

    // Add blank line before Buttons Box.
    mainLayout->addSpacing(25);

    // Create Ok ButtonBoxBox.
    const bool SHOULD_DISPLAY_ICONS = mConfigDialog->
        getBoolSetting(ConfigDialog::SHOW_ICONS_ON_BUTTONS);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok, this);
    QPushButton* okButton = buttonBox->button(QDialogButtonBox::Ok);
    okButton->setText(tr("Ok"));
    if (SHOULD_DISPLAY_ICONS) {
        okButton->setIcon(QIcon::fromTheme("dialog-ok"));
    } else {
        okButton->setIcon(QIcon());
    }

    // Connect Ok and Repo signals.
    connect(buttonBox, &QDialogButtonBox::accepted, this,
        &QDialog::accept);

    mainLayout->addWidget(buttonBox);
}

/**
 * Destructor.
 */
RedDialog::~RedDialog() {
}

/**
 * Close the RedDialog when the window is closed
 * by clicking top-right 'X' button.
 *
 * Accept the close event so the system knows we handled
 * the window destruction.
 */
void
RedDialog::closeEvent(QCloseEvent* event) {
    reject();

    event->accept();
}

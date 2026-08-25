
// App headers.
#include "Globals.h"
#include "AboutDialog.h"

#include "ConfigDialog.h"

// C Headers.
#include <iostream>
using namespace std;

// Qt Headers.
#include <QCloseEvent>
#include <QDesktopServices>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

// LXQt Headers.
#include <lxqt/pluginsettings.h>

/**
 * Simple class to represent an AboutDialog.
 */
AboutDialog::AboutDialog(PluginSettings* settings,
    ConfigDialog* parent) : QDialog(parent) {
    setMinimumWidth(600);

    // Save App ref.
    mSettings = settings;

    // Set title & icon.
    setWindowFlags(Qt::Dialog | Qt::Tool);
    setWindowTitle(gTranslationHelper->getTranslationOf("About",
        gConfigDialog->getStringSetting(ConfigDialog::
        APP_LANGUAGE)) + QString(" ") + mSettings->group());
    setWindowIcon(QIcon::fromTheme(APP_ICON));

    // Create overall container.
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->addSpacing(20);

    // App title line.
    QLabel* appTitleLine = new QLabel(QString(APP_NAME), this);
    appTitleLine->setAlignment(Qt::AlignCenter);
    appTitleLine->setWordWrap(true);
    QFont appTitleFont = appTitleLine->font();
    appTitleFont.setPointSize(FONT_BASE_SIZE + 8);
    appTitleFont.setBold(true);
    appTitleFont.setItalic(true);
    appTitleLine->setFont(appTitleFont);
    QPalette appTitlePalette = appTitleLine->palette();
    appTitlePalette.setColor(QPalette::WindowText, QColor("#1ed760"));
    appTitleLine->setPalette(appTitlePalette);
    mainLayout->addWidget(appTitleLine);

    // App versions line.
    QLabel* appVersionsLine = new QLabel(QString(APP_VERSION) +
        QString(" : ") + QString(APP_VERSION_MINOR), this);
    appVersionsLine->setMargin(0);
    appVersionsLine->setAlignment(Qt::AlignCenter);
    appVersionsLine->setWordWrap(true);
    QFont appVersionsFont = appVersionsLine->font();
    appVersionsFont.setPointSize(FONT_BASE_SIZE + 2);
    appVersionsLine->setFont(appVersionsFont);
    mainLayout->addWidget(appVersionsLine);
    mainLayout->addSpacing(10);

    // App description line.
    QLabel* appDescLine = new QLabel(gTranslationHelper->
        getTranslationOf(APP_DESC, gConfigDialog->
        getStringSetting(ConfigDialog::APP_LANGUAGE)), this);
    appDescLine->setAlignment(Qt::AlignCenter);
    appDescLine->setWordWrap(true);
    QFont appDescFont = appDescLine->font();
    appDescFont.setPointSize(FONT_BASE_SIZE + 4);
    appDescFont.setItalic(true);
    appDescLine->setFont(appDescFont);
    mainLayout->addWidget(appDescLine);
    mainLayout->addSpacing(10);

    // App author & org line.
    QLabel* appAuthorLine = new QLabel(QString(APP_AUTHOR) +
        QString("\n") + QString(ORG_NAME), this);
    appAuthorLine->setAlignment(Qt::AlignCenter);
    appAuthorLine->setWordWrap(true);
    QFont appAuthorFont = appAuthorLine->font();
    appAuthorFont.setPointSize(FONT_BASE_SIZE + 2);
    appAuthorLine->setFont(appAuthorFont);
    mainLayout->addWidget(appAuthorLine);
    mainLayout->addSpacing(15);

    // Credits line.
    QLabel* iconCreditsLine = new QLabel(this);
    iconCreditsLine->setText(gTranslationHelper->getTranslationOf(
        "Icon artwork provided by", gConfigDialog->
        getStringSetting(ConfigDialog::APP_LANGUAGE)) +
        " <a href=\"https://www.123rf.com/stock-photo/" +
        "stoplight_cartoon_outline.html\">" + QString("123RF") + "</a>");
    iconCreditsLine->setOpenExternalLinks(true);
    iconCreditsLine->setTextInteractionFlags(
        Qt::LinksAccessibleByMouse);
    iconCreditsLine->setAlignment(Qt::AlignCenter);
    iconCreditsLine->setWordWrap(true);
    QFont iconCreditsFont = iconCreditsLine->font();
    iconCreditsFont.setPointSize(FONT_BASE_SIZE);
    iconCreditsLine->setFont(iconCreditsFont);
    QPalette iconCreditsPalette = iconCreditsLine->palette();
    iconCreditsPalette.setColor(QPalette::WindowText, QColor("black"));
    iconCreditsLine->setPalette(iconCreditsPalette);
    mainLayout->addWidget(iconCreditsLine);

    // Add blank line before Buttons Box.
    mainLayout->addSpacing(20);

    // Create Ok / Cancel ButtonBoxBox with a Repo button.
    const bool SHOULD_DISPLAY_ICONS = gConfigDialog->
        getBoolSetting(ConfigDialog::SHOW_ICONS_ON_BUTTONS);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok, this);

    QPushButton* okButton = buttonBox->button(QDialogButtonBox::Ok);
    okButton->setText(gTranslationHelper->getTranslationOf("Ok",
        gConfigDialog->getStringSetting(ConfigDialog::
            APP_LANGUAGE)));
    if (SHOULD_DISPLAY_ICONS) {
        okButton->setIcon(QIcon::fromTheme("dialog-ok"));
    } else {
        okButton->setIcon(QIcon());
    }

    QPushButton* repoButton = new QPushButton(gTranslationHelper->
        getTranslationOf("Repo", gConfigDialog->
            getStringSetting(ConfigDialog::APP_LANGUAGE)));
    if (SHOULD_DISPLAY_ICONS) {
        repoButton->setIcon(QIcon::fromTheme("internet-web-browser"));
    } else {
        repoButton->setIcon(QIcon());
    }
    buttonBox->addButton(repoButton, QDialogButtonBox::ActionRole);

    // Connect Ok and Repo signals.
    connect(buttonBox, &QDialogButtonBox::accepted, this,
        &QDialog::accept);
    connect(repoButton, &QPushButton::clicked, this, [this]() {
        QDesktopServices::openUrl(QUrl(QStringLiteral(SOURCE_REPO)));
        this->close();
    });

    mainLayout->addWidget(buttonBox);
}

/**
 * Destructor.
 */
AboutDialog::~AboutDialog() {
    delete gTranslationHelper;
}

/**
 * Close the AboutDialog when the window is closed
 * by clicking top-right 'X' button.
 *
 * Accept the close event so the system knows we handled
 * the window destruction.
 */
void
AboutDialog::closeEvent(QCloseEvent* event) {
    reject();

    event->accept();
}


// App Headers.
#include "ConfigDialog.h"
#include "RedDialog.h"
#include "StopLight.h"
#include "StopLightView.h"
#include "YellowDialog.h"

// C Headers.
#include <iomanip>
#include <iostream>

// Qt6 Headers.
#include <QPainter>
#include <QResizeEvent>
#include <QStorageInfo>
#include <QTimer>

/**
 * The main panel plugin view is a basic colored indicator
 * (🔴, 🟡. 🟢) with optional freeSpace%.
 */
StopLightView::StopLightView(StopLight* stopLight,
    ConfigDialog* configDialog, PluginSettings* settings,
    QWidget* parent) : QLabel(parent) {

    // Save App ref.
    mStopLight = stopLight;
    mConfigDialog = configDialog;
    mSettings = settings;

    // Create & start Size Change timer.
    mCheckSpaceTimer = new QTimer(this);
    const int UPDATE_INTERVAL = mConfigDialog->getIntSetting(
        ConfigDialog::INDICATOR_UPDATE_MINS) * 60 * 1000;
    mCheckSpaceTimer->setInterval(UPDATE_INTERVAL);

    // Set connections to trigger warning Dialogs.
    connect(mCheckSpaceTimer, &QTimer::timeout, this, [this]() {
        if (isYellowIndicatorVisible() && mConfigDialog->
            getBoolSetting(ConfigDialog::SHOW_YELLOW_DIALOG)) {
            if (!mYellowDialog || !mYellowDialog->isVisible()) {
                mYellowDialog = new YellowDialog(mConfigDialog, mSettings);
                mYellowDialog->show();
            }
        }
        if (isRedIndicatorVisible() && mConfigDialog->
            getBoolSetting(ConfigDialog::SHOW_RED_DIALOG)) {
            if (!mRedDialog || !mRedDialog->isVisible()) {
                mRedDialog = new RedDialog(mConfigDialog, mSettings);
                mRedDialog->show();
            }
        }
        update();
    });
    mCheckSpaceTimer->start();
}

/**
 * Destructor & cleanup.
 */
StopLightView::~StopLightView() {
    // Stop timer.
    mCheckSpaceTimer->stop();
}

/**
 * Update the view timer with maybe new ConfigDialog value.
 */
void
StopLightView::updateTimerInterval() {
    const int UPDATE_INTERVAL = mConfigDialog->
        getIntSetting(ConfigDialog::INDICATOR_UPDATE_MINS) * 60 * 1000;

    if (mCheckSpaceTimer->interval() != UPDATE_INTERVAL) {
        mCheckSpaceTimer->start(UPDATE_INTERVAL);
    }
}

/**
 * Resize event resizes us.
 */
void
StopLightView::resizeEvent(QResizeEvent* event) {
    setPluginWidth();

    QLabel::resizeEvent(event);
}

/**
 * Redraw the view after configuration changes.
 */
void
StopLightView::redrawAfterConfigChanges() {
    updateTimerInterval();

    setPluginWidth();

    mStopLight->pluginFlagsChanged();

    updateGeometry();
    update();
}

/**
 * Update the plugin view with maybe new size.
 */
void
StopLightView::setPluginWidth() {
    // Get desired width squared down from height.
    const int MARGIN_WIDTH_PCT = mConfigDialog->getIntSetting(
        ConfigDialog::INDICATOR_MARGIN_SIZE);
    const int HEIGHT = height();

    int newWidthSize = (MARGIN_WIDTH_PCT == 0) ?
        HEIGHT : HEIGHT + (HEIGHT * MARGIN_WIDTH_PCT / 100);

    const bool SHOW_ICON_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_ICON_INDICATOR);
    const bool SHOW_TEXT_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_TEXT_INDICATOR);
    if (!SHOW_ICON_INDICATOR && !SHOW_TEXT_INDICATOR &&
        !isGreenIndicatorVisible() && !isYellowIndicatorVisible() &&
        !isRedIndicatorVisible()) {
        newWidthSize = 0;
    }

    if (this->width() != newWidthSize) {
        setFixedWidth(newWidthSize);
    }
}

/**
 * Paint event redraws the whole indicator view.
 */
void
StopLightView::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Maybe draw colored indicators.
    drawIndicator(painter);

    // Maybe draw Freespace text.
    drawTextIndicator(painter);

    // Maybe draw app icon indicator.
    drawIconAsIndicator(painter);
}

/**
 * Maybe draw colored indicators.
 */
void
StopLightView::drawIndicator(QPainter& painter) {
    // Green status?
    if (isGreenIndicatorVisible()) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::green);
        painter.drawEllipse(getIndicatorRect());
        return;
    }

    if (isYellowIndicatorVisible()) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::yellow);
        painter.drawEllipse(getIndicatorRect());
        return;
    }

    if (isRedIndicatorVisible()) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::red);
        painter.drawEllipse(getIndicatorRect());
        return;
    }
}

/**
 * Determine if green indicator level is reached & able
 * to be displayed.
 */
bool
StopLightView::isGreenIndicatorVisible() {
    // If we're green status.
    const bool SHOW_GREEN_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_GREEN_INDICATOR);
    const bool AT_GREEN_LEVEL = isGreenIndicatorLevel();

    return SHOW_GREEN_INDICATOR && AT_GREEN_LEVEL;
}

/**
 * Does our free space amount fall into the green level.
 */
bool
StopLightView::isGreenIndicatorLevel() {
    const int FREE_SPACE = getFreeSpaceAsPercent();

    const int SHOW_YELLOW_AT_THRESHOLD = mConfigDialog->getIntSetting(
        ConfigDialog::SHOW_YELLOW_AT_THRESHOLD);

    return FREE_SPACE > SHOW_YELLOW_AT_THRESHOLD;
}

/**
 * Determine if yellow indicator level is reached & able
 * to be displayed.
 */
bool
StopLightView::isYellowIndicatorVisible() {
    // If we're yellow status.
    const bool SHOW_YELLOW_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_YELLOW_INDICATOR);
    const bool AT_YELLOW_LEVEL = isYellowIndicatorLevel();

    return SHOW_YELLOW_INDICATOR && AT_YELLOW_LEVEL;
}

/**
 * Does our free space amount fall into the yellow level.
 */
bool
StopLightView::isYellowIndicatorLevel() {
    const int FREE_SPACE = getFreeSpaceAsPercent();

    const int SHOW_YELLOW_AT_THRESHOLD = mConfigDialog->getIntSetting(
        ConfigDialog::SHOW_YELLOW_AT_THRESHOLD);
    const int SHOW_RED_AT_THRESHOLD = mConfigDialog->getIntSetting(
        ConfigDialog::SHOW_RED_AT_THRESHOLD);

    return FREE_SPACE <= SHOW_YELLOW_AT_THRESHOLD &&
        FREE_SPACE > SHOW_RED_AT_THRESHOLD;
}

/**
 * Determine if red indicator level is able to be displayed.
 */
bool
StopLightView::isRedIndicatorVisible() {
    // If we're red status.
    const bool SHOW_RED_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_RED_INDICATOR);
    const bool AT_RED_LEVEL = isRedIndicatorLevel();

    return SHOW_RED_INDICATOR && AT_RED_LEVEL;
}

/**
 * Does our free space amount fall into the red level.
 */
bool
StopLightView::isRedIndicatorLevel() {
    const int FREE_SPACE = getFreeSpaceAsPercent();

    const int SHOW_RED_AT_THRESHOLD = mConfigDialog->getIntSetting(
        ConfigDialog::SHOW_RED_AT_THRESHOLD);

    return FREE_SPACE <= SHOW_RED_AT_THRESHOLD;
}

/**
 * Maybe draw the Freespace text indicator.
 */
void
StopLightView::drawTextIndicator(QPainter& painter) {
    if (!shouldDrawTextIndicator()) {
        return;
    }

    // Determine current free space, and indicator text.
    const int FREE_SPACE = getFreeSpaceAsPercent();
    const QString INDICATOR_TEXT = QString::number(FREE_SPACE) + "%";

    const int WIDTH = width();
    const int HEIGHT = height();

    const int INSIDE_MARGIN_WIDTH_PCT = 100 - mConfigDialog->
        getIntSetting(ConfigDialog::INDICATOR_SIZE);
    const int INSIDE_MARGIN_WIDTH = INSIDE_MARGIN_WIDTH_PCT == 0 ?
        0 : (HEIGHT * INSIDE_MARGIN_WIDTH_PCT / 100);

    const int DIAMETER = qMin(WIDTH, HEIGHT) - INSIDE_MARGIN_WIDTH;
    const int TEXT_PCT = mConfigDialog->getIntSetting(
            ConfigDialog::INDICATOR_TEXT_SIZE);

    const int TEXT_DIAMETER = DIAMETER * TEXT_PCT / 100;
    const QRectF INDICATOR_RECT = QRectF((WIDTH - TEXT_DIAMETER) / 2.0,
        (HEIGHT - TEXT_DIAMETER) / 2.0, TEXT_DIAMETER, TEXT_DIAMETER);

    // Reduce indicator text to fit panel.
    QFont textFont = painter.font();
    textFont.setPointSizeF(height() * 0.45);
    QFontMetricsF textMetrics(textFont);
    while (textMetrics.horizontalAdvance(INDICATOR_TEXT) >
        INDICATOR_RECT.width() && textFont.pointSizeF() > 1.0) {
        textFont.setPointSizeF(textFont.pointSizeF() - 0.5);
        textMetrics = QFontMetricsF(textFont);
    }
    painter.setFont(textFont);

    // Set color & draw.
    painter.setPen(Qt::black);
    painter.drawText(INDICATOR_RECT, Qt::AlignCenter,
        INDICATOR_TEXT);
}

/**
 * Determine if should draw the Freespace text indicator.
 */
bool
StopLightView::shouldDrawTextIndicator() {
    const bool SHOW_GREEN_TEXT = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_GREEN_TEXT);
    const bool SHOW_YELLOW_TEXT = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_YELLOW_TEXT);
    const bool SHOW_RED_TEXT = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_RED_TEXT);

    const bool SHOW_TEXT_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_TEXT_INDICATOR);

    return SHOW_TEXT_INDICATOR ||
        (isGreenIndicatorVisible() && SHOW_GREEN_TEXT) ||
        (isYellowIndicatorVisible() && SHOW_YELLOW_TEXT) ||
        (isRedIndicatorVisible() && SHOW_RED_TEXT);
}

/**
 * Maybe draw app icon indicator.
 */
void
StopLightView::drawIconAsIndicator(QPainter& painter) {
    if (!shouldDrawIconIndicator()) {
        // TODO: Empty view, shorten to width 0;
        return;
    }

    // Get textIndicator metrics & rect.
    const QRectF INDICATOR_RECT = getIndicatorRect();
    mConfigDialog->windowIcon().paint(&painter,INDICATOR_RECT.toRect(),
        Qt::AlignCenter);
}

/**
 * Determine if should draw the app icon indicator.
 */
bool
StopLightView::shouldDrawIconIndicator() {
    const bool SHOW_TEXT_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_TEXT_INDICATOR);
    const bool SHOW_ICON_INDICATOR = mConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_ICON_INDICATOR);

    return SHOW_ICON_INDICATOR &&
        !isGreenIndicatorVisible() && !isYellowIndicatorVisible() &&
        !isRedIndicatorVisible() && !SHOW_TEXT_INDICATOR;
}

/**
 * Returns a QRect with the position & size of our desired
 * plugin draw factoring in user size prefs.
 */
QRectF
StopLightView::getIndicatorRect() {
    const int WIDTH = width();
    const int HEIGHT = height();

    const int INSIDE_MARGIN_WIDTH_PCT = 100 -
        mConfigDialog->getIntSetting(
            ConfigDialog::INDICATOR_SIZE);

    const int INSIDE_MARGIN_WIDTH = INSIDE_MARGIN_WIDTH_PCT == 0 ?
        0 : (HEIGHT * INSIDE_MARGIN_WIDTH_PCT / 100);

    const int DIAMETER = qMin(WIDTH, HEIGHT) - INSIDE_MARGIN_WIDTH;

    return QRectF((WIDTH - DIAMETER) / 2.0, (HEIGHT - DIAMETER) / 2.0,
        DIAMETER, DIAMETER);
}

/**
 * Retrieves freespace info of the system root volume.
 */
int
StopLightView::getFreeSpaceAsPercent() {
    const QStorageInfo SI("/");

    return (!SI.isValid() || !SI.isReady() || SI.bytesTotal() == 0) ?
        0 : SI.bytesAvailable() * 100 / SI.bytesTotal();
}

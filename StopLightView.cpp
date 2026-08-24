
// App headers.
#include "Globals.h"
#include "StopLightView.h"

#include "ConfigDialog.h"
#include "StopLight.h"
#include "TranslationHelper.h"

// C headers.
#include <iomanip>
#include <iostream>

// Qt6 headers.
#include <QPainter>
#include <QResizeEvent>
#include <QStorageInfo>
#include <QTimer>

/**
 * The main panel plugin view is a basic colored indicator (🟢, 🔴, 🟡)
 * with optional text % value inside.
 */
StopLightView::StopLightView(StopLight* stopLight, QWidget* parent) :
    QLabel(parent) {

    // Save App ref.
    mStopLight = stopLight;

    // Create & start Size Change timer.
    mCheckSpaceTimer = new QTimer(this);
    const int UPDATE_INTERVAL = gConfigDialog->getIntSetting(
        ConfigDialog::INDICATOR_UPDATE_MINS) * 60 * 1000;
    mCheckSpaceTimer->setInterval(UPDATE_INTERVAL);
    connect(mCheckSpaceTimer, &QTimer::timeout, this, [this]() {
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
    const int UPDATE_INTERVAL = gConfigDialog->
        getIntSetting(ConfigDialog::INDICATOR_UPDATE_MINS) * 60 * 1000;

    if (mCheckSpaceTimer->interval() != UPDATE_INTERVAL) {
        mCheckSpaceTimer->start(UPDATE_INTERVAL);
    }
}

/**
 * Update the plugin view with maybe new size.
 */
void
StopLightView::setPluginWidth() {
    // Get desired width squared down from height.
    const int HEIGHT = height();

    const int MARGIN_WIDTH_PCT = gConfigDialog->
        getIntSetting(ConfigDialog::INDICATOR_MARGIN_SIZE);
    const int WIDTH_PLUS_MARGIN = MARGIN_WIDTH_PCT == 0 ?
        HEIGHT : HEIGHT + (HEIGHT * MARGIN_WIDTH_PCT / 100);

    if (this->width() != WIDTH_PLUS_MARGIN) {
        setFixedWidth(WIDTH_PLUS_MARGIN);
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
 * Paint event redraws the whole indicator view.
 */
void
StopLightView::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // If widget called to show no indicators(?!), show Icon.
    { const bool SHOW_GREEN = gConfigDialog->getBoolSetting(
          ConfigDialog::SHOW_GREEN_INDICATOR);
      const bool SHOW_YELLOW = gConfigDialog->getBoolSetting(
          ConfigDialog::SHOW_YELLOW_INDICATOR);
      const bool SHOW_RED = gConfigDialog->getBoolSetting(
          ConfigDialog::SHOW_RED_INDICATOR);
      const bool SHOW_TEXT = gConfigDialog->getBoolSetting(
          ConfigDialog::SHOW_TEXT_INDICATOR);
      if (!SHOW_GREEN && !SHOW_YELLOW && !SHOW_RED && !SHOW_TEXT) {
          drawIconAsIndicator(painter);
          return;
      }
    }

    // Maybe draw colored indicators.
    drawIndicator(painter);

    // Maybe draw Freespace text.
    drawTextIndicator(painter);
}


/**
 * If widget called to show no indicators(?!), show Icon.
 */
void
StopLightView::drawIconAsIndicator(QPainter& painter) {
    // Get textIndicator metrics & rect.
    const QRectF INDICATOR_RECT = getIndicatorRect();

    gConfigDialog->windowIcon().paint(&painter,
        INDICATOR_RECT.toRect(),Qt::AlignCenter);
}

/**
 * Maybe draw colored indicators.
 */
void
StopLightView::drawIndicator(QPainter& painter) {
    // Determine current free space.
    const int FREE_SPACE = getFreeSpaceAsPercent();

    // If we're green status.
    const int YELLOW_THRESHOLD = gConfigDialog->getIntSetting(
        ConfigDialog::YELLOW_INDICATOR_THRESHOLD);
    if (FREE_SPACE > YELLOW_THRESHOLD) {
        if (gConfigDialog->getBoolSetting(
            ConfigDialog::SHOW_GREEN_INDICATOR)) {
            painter.setPen(Qt::NoPen);
            painter.setBrush(Qt::green);
            painter.drawEllipse(getIndicatorRect());
        }
        return;
    }

    // If we're yellow status.
    const int RED_THRESHOLD = gConfigDialog->getIntSetting(
        ConfigDialog::RED_INDICATOR_THRESHOLD);
    if (FREE_SPACE > RED_THRESHOLD) {
        if (gConfigDialog->getBoolSetting(
            ConfigDialog::SHOW_YELLOW_INDICATOR)) {
            painter.setPen(Qt::NoPen);
            painter.setBrush(Qt::yellow);
            painter.drawEllipse(getIndicatorRect());
        }
        return;
    }

    // We're red status.
    if (gConfigDialog->getBoolSetting(
        ConfigDialog::SHOW_RED_INDICATOR)) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::red);
        painter.drawEllipse(getIndicatorRect());
    }
}

/**
 * Maybe draw Freespace text.
 */
void
StopLightView::drawTextIndicator(QPainter& painter) {
    if (!gConfigDialog->getBoolSetting(ConfigDialog::
        SHOW_TEXT_INDICATOR)) {
        return;
    }

    // Determine current free space, and indicator text.
    const int FREE_SPACE = getFreeSpaceAsPercent();
    const QString INDICATOR_TEXT = QString::number(FREE_SPACE) + "%";


    const int WIDTH = width();
    const int HEIGHT = height();

    const int INSIDE_MARGIN_WIDTH_PCT = 100 - gConfigDialog->
        getIntSetting(ConfigDialog::INDICATOR_SIZE);
    const int INSIDE_MARGIN_WIDTH = INSIDE_MARGIN_WIDTH_PCT == 0 ?
        0 : (HEIGHT * INSIDE_MARGIN_WIDTH_PCT / 100);

    const int DIAMETER = qMin(WIDTH, HEIGHT) - INSIDE_MARGIN_WIDTH;
    const int TEXT_PCT = gConfigDialog->getIntSetting(
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
 * Returns a QRect with the position & size of our desired
 * plugin draw factoring in user size prefs.
 */
QRectF
StopLightView::getIndicatorRect() {
    const int WIDTH = width();
    const int HEIGHT = height();

    const int INSIDE_MARGIN_WIDTH_PCT = 100 -
        gConfigDialog->getIntSetting(
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

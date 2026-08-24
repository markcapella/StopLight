
#pragma once

// App forward decls.
class StopLight;
class ConfigDialog;

// Qt6 headers.
#include <QLabel>

// Qt6 forward decls.
class QPainter;
class QResizeEvent;
class QTimer;

/**
 * The main panel plugin view is a basic colored indicator (🟢, 🔴, 🟡)
 * with optional text % value inside.
 */
class StopLightView : public QLabel {
    Q_OBJECT

    public:
        /**
         * Constructor.
         */
        explicit StopLightView(StopLight* stopLight,
            QWidget* parent = nullptr);

        /**
         * Destructor & cleanup.
         */
        ~StopLightView() override;

        /**
         * Update the view timer with maybe new ConfigDialog value.
         */
        void updateTimerInterval();

        /**
         * Update the plugin view with maybe new size.
         */
        void setPluginWidth();

    protected:
        /**
         * Resize event resizes us.
         */
        void resizeEvent(QResizeEvent* event) override;

        /**
         * Paint event redraws the whole indicator view.
         */
        void paintEvent(QPaintEvent* event) override;

    private:
        // Members.
        StopLight* mStopLight = nullptr;
        QTimer* mCheckSpaceTimer = nullptr;

        /**
         * Draws the StopLight Icon
         */
        void drawIconAsIndicator(QPainter& painter);

        /**
         * Maybe draw colored indicators.
         */
        void drawIndicator(QPainter& painter);

        /**
         * Maybe draw Freespace text.
         */
        void drawTextIndicator(QPainter& painter);

        /**
         * Returns a QRect with the position & size of our desired
         * plugin draw factoring in user size prefs.
         */
        QRectF getIndicatorRect();

        /**
         * Retrieves freespace info of the system root volume.
         */
        int getFreeSpaceAsPercent();
};

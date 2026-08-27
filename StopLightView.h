
#pragma once

// App forward decls.
class ConfigDialog;
class StopLight;
class RedDialog;
class YellowDialog;

// Qt6 Headers.
#include <QLabel>

// Qt6 forward decls.
class QPainter;
class QResizeEvent;
class QTimer;

// LXQT forward decls.
class PluginSettings;

/**
 * The main panel plugin view is a basic colored indicator
 * (🔴, 🟡. 🟢) with optional freeSpace%.
 */
class StopLightView : public QLabel {
    Q_OBJECT

    public:
        /**
         * Constructor.
         */
        explicit StopLightView(StopLight* stopLight,
            ConfigDialog* configDialog, PluginSettings* settings,
            QWidget* parent = nullptr);

        /**
         * Destructor & cleanup.
         */
        ~StopLightView() override;

        /**
         * Update the view timer with maybe new ConfigDialog value.
         */
        void updateTimerInterval();

    protected:
        /**
         * Resize event resizes us.
         */
        void resizeEvent(QResizeEvent* event) override;

    public:
        /**
         * Redraw the view after configuration changes.
         */
        void redrawAfterConfigChanges();

        /**
         * Update the plugin view with maybe new size.
         */
        void setPluginWidth();

    protected:
        /**
         * Paint event redraws the whole indicator view.
         */
        void paintEvent(QPaintEvent* event) override;

    private:
        /**
         * Maybe draw colored indicators.
         */
        void drawIndicator(QPainter& painter);

        /**
         * Determine if green indicator level is reached & able
         * to be displayed.
         */
        bool isGreenIndicatorVisible();

        /**
         * Does our free space amount fall into the green level.
         */
        bool isGreenIndicatorLevel();

        /**
         * Determine if yellow indicator level is reached & able
         * to be displayed.
         */
        bool isYellowIndicatorLevel();

        /**
         * Does our free space amount fall into the yellow level.
         */
        bool isYellowIndicatorVisible();

        /**
         * Determine if red indicator level able to be displayed.
         */
        bool isRedIndicatorVisible();

        /**
         * Does our free space amount fall into the red level.
         */
        bool isRedIndicatorLevel();

        /**
         * Maybe draw the Freespace text indicator.
         */
        void drawTextIndicator(QPainter& painter);

        /**
         * Determine if should draw the Freespace text indicator.
         */
        bool shouldDrawTextIndicator();

        /**
         * Maybe draw app icon indicator.
         */
        void drawIconAsIndicator(QPainter& painter);

        /**
         * Determine if should draw the app icon indicator.
         */
        bool shouldDrawIconIndicator();

        /**
         * Returns a QRect with the position & size of our desired
         * plugin draw factoring in user size prefs.
         */
        QRectF getIndicatorRect();

        /**
         * Retrieves freespace info of the system root volume.
         */
        int getFreeSpaceAsPercent();

        /**
         * Members.
         */
        StopLight* mStopLight = nullptr;
        ConfigDialog* mConfigDialog = nullptr;
        PluginSettings* mSettings;

        QTimer* mCheckSpaceTimer = nullptr;

        YellowDialog* mYellowDialog = nullptr;
        RedDialog* mRedDialog = nullptr;

};

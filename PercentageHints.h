
#pragma once

// App forward decls.
class ConfigDialog;
class StopLightView;

// Qt Headers.
#include <QEvent>
#include <QToolTip>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

/**
 * Tooltip hints for sliders that represent a percentage of 100.
 */
struct PercentageHints : public QObject {

    public:
        /**
         * Constructor.
         */
        PercentageHints(QSlider* slider) :
             QObject(slider), s(slider) { }

        /**
         * Catch events to trigger hover info.
         */
        bool eventFilter(QObject* o, QEvent* e) override {
            // Show the immediate millisecond the mouse
            // crosses into the slider.
            if (e->type() == QEvent::Enter) {
                if (!s->isSliderDown()) {
                    const QString TOOLTIP_TEXT = QString::number(
                        s->value()) + "%";
                    QToolTip::showText(QCursor::pos(), TOOLTIP_TEXT, s);
                }
                return false;
            }

            // Show also on interaction.
            if (e->type() == QEvent::ToolTip ||
                e->type() == QEvent::MouseMove) {
                if (!s->isSliderDown()) {
                    const QString TOOLTIP_TEXT = QString::number(
                        s->value()) + "%";
                    QToolTip::showText(QCursor::pos(), TOOLTIP_TEXT, s);
                }
            }
            return false;
        }

    private:
        // Members.
        QSlider* s = nullptr;
};

#pragma GCC diagnostic pop

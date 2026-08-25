
#pragma once

// App headers.
#include "Globals.h"
#include "TranslationHelper.h"

// Qt Headers.
#include <QEvent>
#include <QToolTip>

// Qt6 forward decls.
class QSlider;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

/**
 * Tooltip hints for sliders that represent time in minutes.
 */
struct MinutesHints : public QObject {

    public:
        /**
         * Constructor.
         */
        MinutesHints(QSlider* slider) :
            QObject(slider), s(slider) {
        }

    protected:
        /**
         * Catch events to trigger hover info.
         */
        bool eventFilter(QObject* o, QEvent* e) override {
            // Show the immediate millisecond the mouse
            // crosses into the slider.
            if (e->type() == QEvent::Enter) {
                if (!s->isSliderDown()) {
                    const int VALUE = s->value();
                    const QString I18N_UPDATE_TIME = (VALUE == 1) ?
                        gTranslationHelper->getTranslationOf("minute",
                            gConfigDialog->getStringSetting(
                                ConfigDialog::APP_LANGUAGE)) :
                        gTranslationHelper->getTranslationOf("minutes",
                            gConfigDialog->getStringSetting(
                                ConfigDialog::APP_LANGUAGE));
                    const QString TOOLTIP_TEXT = QString::number(VALUE) +
                        " " + I18N_UPDATE_TIME;
                    QToolTip::showText(QCursor::pos(), TOOLTIP_TEXT, s);
                }
                return false;
            }

            // Show also on interaction.
            if (e->type() == QEvent::ToolTip ||
                e->type() == QEvent::MouseMove) {
                if (!s->isSliderDown()) {
                    const int VALUE = s->value();
                    const QString I18N_UPDATE_TIME = (VALUE == 1) ?
                        gTranslationHelper->getTranslationOf("minute",
                            gConfigDialog->getStringSetting(
                                ConfigDialog::APP_LANGUAGE)) :
                        gTranslationHelper->getTranslationOf("minutes",
                            gConfigDialog->getStringSetting(
                                ConfigDialog::APP_LANGUAGE));
                    const QString TOOLTIP_TEXT = QString::number(VALUE) +
                        " " + I18N_UPDATE_TIME;
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

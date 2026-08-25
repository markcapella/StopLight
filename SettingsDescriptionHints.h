
#pragma once

#include "Globals.h"

/**
 * Tooltip hints for Settings that explain their function.
 */
class SettingsDescriptionHints : public QObject {

    public:
        /**
         * Constructor.
         */
        SettingsDescriptionHints(const QString english,
            QObject* parent = nullptr) : QObject(parent),

            // Save our english text for runtime conversion.
            mEnglishText(english) {
        }

    protected:
        /**
         * Catch events to trigger hover info.
         */
        bool eventFilter(QObject* setting, QEvent* event) override {
            const bool SHOW_SETTINGS_HINTS = gConfigDialog->getBoolSetting(
                ConfigDialog::SHOW_SETTINGS_HINTS);

            if (SHOW_SETTINGS_HINTS) {
                if (event->type() == QEvent::Enter) {
                    const QString TRANSLATED_ENGLISH = gTranslationHelper->
                        getTranslationOf(mEnglishText, gConfigDialog->
                        getStringSetting(ConfigDialog::APP_LANGUAGE));
                    QToolTip::showText(QCursor::pos(), TRANSLATED_ENGLISH,
                        qobject_cast<QWidget*>(setting));
                }
                else if (event->type() == QEvent::Leave) {
                    QToolTip::hideText();
                }
            }

            return QObject::eventFilter(setting, event);
        }

    private:
        // Members.
        QString mEnglishText;

};


// App headers.
#include "ConfigDialog.h"
#include "TranslationHelper.h"

// C Headers.
#include <iostream>
using namespace std;

/**
 * TranslationHelper takes an english string and returns
 * a translated string for a desired language at runtime.
 *
 * Strings are collected & translated at build time,
 * then appropriately displayed at runtime.
 */
TranslationHelper::TranslationHelper() {
}

/**
 * Returns english text translated to language text.
 */
QString
TranslationHelper::getTranslationOf(const QString english,
    const QString language) {

    const int TRANSLATIONS_SIZE = ALL_TRANSLATIONS.size();
    for (int i = 0; i < TRANSLATIONS_SIZE; i++) {
        const QStringList TRANSLATION_SET = ALL_TRANSLATIONS[i];

        if (TRANSLATION_SET.at(0) == english) {
            const int LANG_INDEX = ALL_LANGUAGES.indexOf(language);
            const QString TRANSLATED_TEXT = TRANSLATION_SET.value(
                LANG_INDEX);
            if (TRANSLATED_TEXT.isEmpty()) {
                return QString("<translation table error>");
            }
            return TRANSLATED_TEXT;
        }
    }

    // Return obvious error if not found.
    return "<translation error>";
}

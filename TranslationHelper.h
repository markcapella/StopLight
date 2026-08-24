
#pragma once

// App headers.
#include "StopLight.h"

// Qt Headers.
#include <QString>

/**
 * TranslationHelper takes an english string and returns
 * a translated string for a desired language at runtime.
 *
 * Strings are collected & translated at build time,
 * then appropriately displayed at runtime.
 */
class TranslationHelper {

    public:
        /**
         * Constructor.
         */
        TranslationHelper();

        /**
         * Returns english text translated to language text.
         */
        QString getTranslationOf(const QString english,
            const QString language);

    private:
        // Members.
};


#pragma once

/**
 * First block is list of all supprted language stings.
 *
 * To add a new language, add an entry here.
 */
const QStringList ALL_LANGUAGES = {
    "en",
    "de",
    "es",
    "fr",
    "it",
    "ja",
    "nl",
    "pt",
    "ru"
};

/**
 * This block contains a translation set for each translatable english
 * text string into the desired languages.
 *
 * The english key is the first line, subsequent lines contain
 * translated string for that key.
 *
 * Entries are in order of (above) ALL_LANGUAGES, of course :)
 *
`* To add a new language, add an entry into all translation sets.
 */
const QStringList TRANSLATION_SET_0 = {
    "About",
    "Über",
    "Acerca de",
    "À propos",
    "Informazioni",
    "約",
    "Over",
    "Sobre",
    "О"
};

const QStringList TRANSLATION_SET_1 = {
    "An lxqt-panel Plugin to let you avoid hitting an empty tank of drive space.",
    "Ein lxqt-Panel-Plugin, das es Ihnen ermöglicht, einen leeren Speicherplatz auf dem Laufwerk zu vermeiden.",
    "Un complemento de lxqt-panel que te permite evitar quedarte sin espacio en el disco.",
    "Un plugin pour lxqt-panel qui vous permet d’éviter de tomber sur un disque dur plein.",
    "Un plugin per lxqt-panel che ti permette di evitare di finire lo spazio su disco.",
    "空のドライブ容量にぶつかるのを避けられる lxqt-panel プラグイン",
    "Een lxqt-panel plugin om te voorkomen dat je een lege schijfruimte tegenkomt.",
    "Um plugin do lxqt-panel que permite evitar atingir um tanque vazio de espaço em disco.",
    "Плагин lxqt-панели, позволяющий избегать столкновения с пустым дисковым пространством."
};

const QStringList TRANSLATION_SET_2 = {
    "Apply",
    "Anwenden",
    "Aplicar",
    "Appliquer",
    "Applicare",
    "適用する",
    "Toepassen",
    "Aplicar",
    "Применить"
};

const QStringList TRANSLATION_SET_3 = {
    "Cancel",
    "Stornieren",
    "Cancelar",
    "Annuler",
    "Cancellare",
    "キャンセル",
    "Annuleren",
    "Cancelar",
    "Отмена"
};

const QStringList TRANSLATION_SET_4 = {
    "Configuration",
    "Konfiguration",
    "Configuración",
    "Configuration",
    "Configurazione",
    "構成",
    "Configuratie",
    "Configuração",
    "Конфигурация"
};

const QStringList TRANSLATION_SET_5 = {
    "Icon artwork provided by",
    "Symbolgrafik bereitgestellt von",
    "Arte de icono proporcionado por",
    "Illustration d'icône fournie par",
    "Illustrazione dell'icona fornita da",
    "アイコンのアートワーク提供者",
    "Pictogramkunst geleverd door",
    "Arte do ícone fornecida por",
    "Иконка предоставлена"
};

const QStringList TRANSLATION_SET_6 = {
    "Language",
    "Sprache",
    "Idioma",
    "Langue",
    "Lingua",
    "言語",
    "Taal",
    "Linguagem",
    "Язык"
};

const QStringList TRANSLATION_SET_7 = {
    "Ok",
    "Ok",
    "Ok",
    "Ok",
    "Ok",
    "「オーケー」",
    "Oké",
    "Ok",
    "Ок"
};

const QStringList TRANSLATION_SET_8 = {
    "Repo",
    "Repo",
    "Repositorio",
    "Dépôt",
    "Repo",
    "リポ",
    "Repo",
    "Repositório",
    "репозиторий"
};

const QStringList TRANSLATION_SET_9 = {
    "Reset",
    "Zurücksetzen",
    "Restablecer",
    "Réinitialiser",
    "Reimposta",
    "リセット",
    "Resetten",
    "Redefinir",
    "Сброс"
};

const QStringList TRANSLATION_SET_10 = {
    "Show Green Indicator",
    "Grünes Symbol anzeigen",
    "Mostrar indicador verde",
    "Afficher l'indicateur vert",
    "Mostra indicatore verde",
    "緑のインジケーターを表示",
    "Toon groen indicator",
    "Mostrar Indicador Verde",
    "Показать зелёный индикатор"
};

const QStringList TRANSLATION_SET_11 = {
    "Show Red Indicator",
    "Rote Anzeige anzeigen",
    "Mostrar indicador rojo",
    "Afficher l'indicateur rouge",
    "Mostra indicatore rosso",
    "赤いインジケーターを表示",
    "Toon rood indicator",
    "Mostrar Indicador Vermelho",
    "Показать красный индикатор"
};

const QStringList TRANSLATION_SET_12 = {
    "Show Red when",
    "Zeige Rot, wenn",
    "Mostrar rojo cuando",
    "Afficher en rouge lorsque",
    "Mostra Rosso quando",
    "〜のときに赤を表示",
    "Toon rood wanneer",
    "Mostrar vermelho quando",
    "Показать красный, когда"
};

const QStringList TRANSLATION_SET_13 = {
    "Show Text Indicator",
    "Textanzeige anzeigen",
    "Mostrar indicador de texto",
    "Afficher l'indicateur de texte",
    "Mostra indicatore di testo",
    "テキスト表示インジケーター",
    "Toon tekstindicator",
    "Mostrar Indicador de Texto",
    "Показать индикатор текста"
};

const QStringList TRANSLATION_SET_14 = {
    "Show Yellow Indicator",
    "Gelben Indikator anzeigen",
    "Mostrar indicador amarillo",
    "Afficher l'indicateur jaune",
    "Mostra indicatore giallo",
    "黄色のインジケーターを表示",
    "Toon geel indicator",
    "Mostrar indicador amarelo",
    "Показать жёлтый индикатор"
};

const QStringList TRANSLATION_SET_15 = {
    "Show Yellow when",
    "Zeige Gelb wenn",
    "Mostrar amarillo cuando",
    "Afficher le jaune quand",
    "Mostra giallo quando",
    "〜のときに黄色を表示",
    "Geel tonen wanneer",
    "Mostrar Amarelo quando",
    "Показывать жёлтый, когда"
};

const QStringList TRANSLATION_SET_16 = {
    "Indicator Margin Size",
    "Indikator-Randgröße",
    "Tamaño del margen del indicador",
    "Taille de la marge de l'indicateur",
    "Dimensione margine indicatore",
    "インジケーターの余白サイズ",
    "Indicator Marge Grootte",
    "Tamanho da Margem do Indicador",
    "Размер отступа индикатора"
};

const QStringList TRANSLATION_SET_17 = {
    "Indicator Size",
    "Anzeigegröße",
    "Tamaño del indicador",
    "Taille de l'indicateur",
    "Dimensione dell'indicatore",
    "インジケーターサイズ",
    "Indicator Grootte",
    "Tamanho do Indicador",
    "Размер индикатора"
};

const QStringList TRANSLATION_SET_18 = {
    "Indicator Text Size",
    "Indikator Textgröße",
    "Tamaño del texto del indicador",
    "Taille du texte de l'indicateur",
    "Dimensione del testo dell'indicatore",
    "インジケーターの文字サイズ",
    "Indicator Tekstgrootte",
    "Tamanho do Texto do Indicador",
    "Размер текста индикатора"
};

const QStringList TRANSLATION_SET_19 = {
    "Show Icons on Buttons",
    "Symbole auf Schaltflächen anzeigen",
    "Mostrar iconos en los botones",
    "Afficher les icônes sur les boutons",
    "Mostra icone sui pulsanti",
    "ボタンにアイコンを表示",
    "Pictogrammen op knoppen weergeven",
    "Mostrar ícones nos botões",
    "Показывать значки на кнопках"
};

const QStringList TRANSLATION_SET_20 = {
    "Time between Indicator Updates",
    "Zeit zwischen den Indikatoraktualisierungen",
    "Tiempo entre actualizaciones del indicador",
    "Temps entre les mises à jour de l'indicateur",
    "Tempo tra gli aggiornamenti dell'indicatore",
    "インジケーター更新間の時間",
    "Tijd tussen indicatorupdates",
    "Tempo entre atualizações do indicador",
    "Время между обновлениями индикатора"
};

const QStringList TRANSLATION_SET_21 = {
    "minute",
    "Minute",
    "minuto",
    "minute",
    "minuto",
    "分",
    "minuut",
    "minuto",
    "минута"
};

const QStringList TRANSLATION_SET_22 = {
    "minutes",
    "Minuten",
    "minutos",
    "minutes",
    "minuti",
    "分",
    "minuten",
    "minutos",
    "минуты"
};

/**
 * Complete searchable table for TranslationHelper.
 */
const vector<QStringList> ALL_TRANSLATIONS = {
    TRANSLATION_SET_0,
    TRANSLATION_SET_1,
    TRANSLATION_SET_2,
    TRANSLATION_SET_3,
    TRANSLATION_SET_4,
    TRANSLATION_SET_5,
    TRANSLATION_SET_6,
    TRANSLATION_SET_7,
    TRANSLATION_SET_8,
    TRANSLATION_SET_9,
    TRANSLATION_SET_10,
    TRANSLATION_SET_11,
    TRANSLATION_SET_12,
    TRANSLATION_SET_13,
    TRANSLATION_SET_14,
    TRANSLATION_SET_15,
    TRANSLATION_SET_16,
    TRANSLATION_SET_17,
    TRANSLATION_SET_18,
    TRANSLATION_SET_19,
    TRANSLATION_SET_20,
    TRANSLATION_SET_21,
    TRANSLATION_SET_22
};

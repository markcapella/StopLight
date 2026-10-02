
#pragma once

// C Headers.
#include <vector>

/**
 * First block is list of all supprted language stings.
 *
 * To add a new language, add an entry here.
 */
static inline const QStringList ALL_LANGUAGES = {
    "en", "de", "es", "fr", "it", "ja", "nl", "pt", "ru"
};

/*
 * Second block contains a translation set for each translatable
 * english text string into the desired languages.
 *
`* To add a new language, add a translation entry into
 * each of the translation sets.
 */

/**
 * Second block - Dialog Headings, Buttons & Hints translations.
 */
const QStringList CONFIGURATION_TEXT = {
    "Configuration", "Konfiguration", "Configuración", "Configuration",
    "Configurazione", "構成", "Configuratie", "Configuração",
    "Конфигурация"
};

const QStringList RESET_TEXT = {
    "Reset", "Zurücksetzen", "Restablecer", "Réinitialiser",
    "Reimposta", "リセット", "Resetten", "Redefinir", "Сброс"
};

const QStringList ABOUT_TEXT = {
    "About", "Über", "Acerca de", "À propos", "Informazioni", "約",
    "Over", "Sobre", "О"
};

const QStringList OK_TEXT = {
    "Ok", "Ok", "Ok", "Ok", "Ok", "「オーケー」", "Oké", "Ok", "Ок"
};

const QStringList APPLY_TEXT = {
    "Apply", "Anwenden", "Aplicar", "Appliquer", "Applicare", "適用する",
    "Toepassen", "Aplicar", "Применить"
};

const QStringList CANCEL_TEXT = {
    "Cancel", "Stornieren", "Cancelar", "Annuler","Cancellare",
    "キャンセル", "Annuleren", "Cancelar", "Отмена"
};

const QStringList REPO_TEXT = {
    "Repo", "Repo", "Repositorio", "Dépôt", "Repo", "リポ", "Repo",
    "Repositório", "репозиторий"
};

const QStringList MINUTE = {
    "minute", "Minute", "minuto", "minute", "minuto", "分", "minuut",
    "minuto", "минута"
};

const QStringList MINUTES = {
    "minutes", "Minuten", "minutos", "minutes", "minuti", "分",
    "minuten", "minutos", "минуты"
};

/**
 * Second block - About Dialog translations.
 */
const QStringList ABOUT_DESCRIPTION = {
    "Provides an indicator & warning dialogs about your system Free Space (🔴, 🟡, 🟢).",
    "Bietet eine Anzeige und Warnmeldungen über den freien Speicherplatz Ihres Systems (🔴, 🟡, 🟢).",
    "Proporciona un indicador y diálogos de advertencia sobre el espacio libre de su sistema (🔴, 🟡, 🟢).",
    "Fournit un indicateur et des boîtes de dialogue d'avertissement concernant l'espace libre de votre système (🔴, 🟡, 🟢).",
    "Fornisce un indicatore e finestre di avviso riguardo lo spazio libero del tuo sistema (🔴, 🟡, 🟢).",
    "システムの空き容量についてのインジケーターと警告ダイアログを提供します（🔴、🟡、🟢）。",
    "Biedt een indicator en waarschuwingsdialogen over de vrije ruimte van uw systeem (🔴, 🟡, 🟢).",
    "Fornece um indicador e diálogos de aviso sobre o Espaço Livre do seu sistema (🔴, 🟡, 🟢).",
    "Предоставляет индикатор и предупреждающие диалоговые окна о свободном месте на вашей системе (🔴, 🟡, 🟢)."
};

const QStringList ABOUT_ARTWORK = {
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

/**
 * Second block - YellowDialog translations.
 */
const QStringList YELLOW_TITLE = {
    "Warning", "Warnung", "Advertencia", "Avertissement", "Avviso",
    "警告", "Waarschuwing", "Aviso", "Предупреждение"
};

const QStringList YELLOW_WARNING = {
    "You've reached the threshold for a Yellow Warning! Check your free space and remove what you can.",
    "Sie haben die Schwelle für eine Gelbe Warnung erreicht! Überprüfen Sie Ihren freien Speicherplatz und entfernen Sie, was Sie können.",
    "¡Has alcanzado el umbral de una Advertencia Amarilla! Revisa tu espacio libre y elimina lo que puedas.",
    "Vous avez atteint le seuil d'un avertissement jaune ! Vérifiez votre espace libre et supprimez ce que vous pouvez.",
    "Hai raggiunto la soglia per un Avviso Giallo! Controlla lo spazio libero e rimuovi ciò che puoi.",
    "あなたはイエロー警告の閾値に達しました！空き容量を確認し、不要なものを削除してください。",
    "Je hebt de drempel voor een Gele Waarschuwing bereikt! Controleer je vrije ruimte en verwijder wat je kunt.",
    "Você atingiu o limite para um Aviso Amarelo! Verifique seu espaço livre e remova o que puder.",
    "Вы достигли порога Желтого Предупреждения! Проверьте свободное место и удалите то, что можете."
};

/**
 * Second block - RedDialog translations.
 */
const QStringList RED_TITLE = {
    "Alert", "Alarm", "Alerta", "Alerte", "Avviso",
    "警告", "Waarschuwing", "Alerta", "Тревога"
};

const QStringList RED_ALERT = {
    "You've reached the threshold for a Red Alert! Check your free space and remove what you can.",
    "Sie haben die Schwelle für eine Rote Alarmstufe erreicht! Überprüfen Sie Ihren freien Speicherplatz und entfernen Sie, was Sie können.",
    "¡Has alcanzado el umbral de una Alerta Roja! Revisa tu espacio libre y elimina lo que puedas.",
    "Vous avez atteint le seuil d'une alerte rouge ! Vérifiez votre espace libre et supprimez ce que vous pouvez.",
    "Hai raggiunto la soglia per un Allarme Rosso! Controlla lo spazio libero e rimuovi ciò che puoi.",
    "レッドアラートの閾値に達しました！空き容量を確認し、不要なものを削除してください。",
    "Je hebt de drempel voor een Rode Alarm bereikt! Controleer je vrije ruimte en verwijder wat je kunt.",
    "Você atingiu o limite para um Alerta Vermelho! Verifique seu espaço livre e remova o que puder.",
    "Вы достигли порога Красного Тревожного сигнала! Проверьте свободное место и удалите то, что можно."
};

/**
 * Second block - Configuration Dialog translations.
 */
const QStringList APP_LANGUAGE = {
    "Language", "Sprache", "Idioma", "Langue", "Lingua", "言語",
    "Taal", "Linguagem", "Язык"
};

const QStringList APP_LANGUAGE_HINT = {
    "The language you'd like to see displayed, when viewing the Configuration or About Dialogs.",
    "Die Sprache, die Sie sehen möchten, wenn Sie die Konfigurations- oder Info-Dialoge anzeigen.",
    "El idioma que le gustaría ver mostrado al visualizar los cuadros de diálogo de Configuración o Acerca de.",
    "La langue que vous souhaitez voir affichée lors de la consultation des dialogues Configuration ou À propos.",
    "La lingua che desideri visualizzare quando visualizzi i dialoghi Configurazione o Informazioni.",
    "設定またはバージョンダイアログを表示したときに表示したい言語。",
    "De taal die u wilt zien weergegeven bij het bekijken van de Configuratie- of Info-dialoogvensters.",
    "O idioma que você gostaria de ver exibido ao visualizar os diálogos de Configuração ou Sobre.",
    "Язык, который вы хотели бы видеть отображаемым при просмотре диалогов Конфигурации или О программе."
};

const QStringList INDICATOR_MARGIN_SIZE = {
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

const QStringList INDICATOR_MARGIN_SIZE_HINT = {
    "Sets left and right margin width of indicator in the panel.",
    "Legt die linke und rechte Randbreite des Indikators im Panel fest.",
    "Establece el ancho del margen izquierdo y derecho del indicador en el panel.",
    "Définit la largeur des marges gauche et droite de l'indicateur dans le panneau.",
    "Imposta la larghezza del margine sinistro e destro dell'indicatore nel pannello.",
    "パネル内のインジケーターの左右の余白幅を設定します。",
    "Stelt de linkermarge- en rechtermargebreedte van de indicator in het paneel in.",
    "Define a largura das margens esquerda e direita do indicador no painel.",
    "Устанавливает ширину левого и правого отступа индикатора на панели."
};

const QStringList INDICATOR_SHRINKS_TO_ROW = {
    "Indicator Shrinks to Row Height",
    "Indikator schrumpft zur Zeilenhöhe",
    "El indicador se reduce a la altura de la fila",
    "L'indicateur se réduit à la hauteur de la ligne",
    "Indicatore si riduce all'altezza della riga",
    "インジケーターが行の高さに縮小",
    "Indicator krimpt tot rijhoogte",
    "Indicador Encolhe para a Altura da Linha",
    "Индикатор сжимается до высоты строки"
};

const QStringList INDICATOR_SHRINKS_TO_ROW_HINT = {
    "Allows indicator to shrink from full panel height to grouped row height.",
    "Ermöglicht dem Indikator, von der vollen Panelhöhe auf die Höhe der gruppierten Zeile zu schrumpfen.",
    "Permite que el indicador se reduzca desde la altura completa del panel hasta la altura de la fila agrupada.",
    "Permet à l'indicateur de se réduire de la hauteur complète du panneau à la hauteur de la ligne groupée.",
    "Permette all'indicatore di ridursi dall'altezza completa del pannello all'altezza della riga raggruppata.",
    "インジケーターが全パネルの高さからグループ化された行の高さに縮小できるようにします。",
    "Staat de indicator toe om te krimpen van de volledige paneelhoogte naar de hoogte van de gegroepeerde rij.",
    "Permite que o indicador diminua de toda a altura do painel para a altura da linha agrupada.",
    "Позволяет индикатору уменьшаться от полной высоты панели до высоты сгруппированной строки."
};

const QStringList INDICATOR_SIZE = {
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

const QStringList INDICATOR_SIZE_HINT = {
    "Sets indicator full size, or some percentage smaller.",
    "Stellt die Indikatorgröße auf voll oder um einen bestimmten Prozentsatz kleiner ein.",
    "Establece el indicador a tamaño completo, o un porcentaje menor.",
    "Définit la taille complète de l'indicateur, ou un pourcentage plus petit.",
    "Imposta le dimensioni complete dell'indicatore o una percentuale inferiore.",
    "インジケーターをフルサイズに設定するか、いくつかのパーセンテージだけ小さくします。",
    "Stelt de indicator in op volledige grootte, of een bepaald percentage kleiner.",
    "Define o indicador em tamanho completo ou em alguma porcentagem menor.",
    "Устанавливает полный размер индикатора или на некоторый меньший процент."
};

const QStringList INDICATOR_TEXT_SIZE = {
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

const QStringList INDICATOR_TEXT_SIZE_HINT = {
    "Sets indicator text fullsize, or some percentage smaller.",
    "Setzt den Indikatortext in voller Größe oder um einen bestimmten Prozentsatz kleiner.",
    "Establece el texto del indicador a tamaño completo, o un porcentaje menor.",
    "Définit le texte de l'indicateur en taille réelle, ou en pourcentage plus petit.",
    "Imposta il testo dell'indicatore a dimensione piena, o qualche percentuale più piccolo.",
    "インジケーターのテキストをフルサイズ、または一部のパーセンテージだけ小さく設定します。",
    "Stelt de indicatortekst in op volledige grootte, of op een bepaald percentage kleiner.",
    "Define o texto do indicador em tamanho cheio ou em algum percentual menor.",
    "Устанавливает текст индикатора в полный размер или на некоторый процент меньше."
};

const QStringList SHOW_GREEN_INDICATOR = {
    "🟢 Show Green Indicator",
    "🟢 Grünen Indikator anzeigen",
    "🟢 Mostrar indicador verde",
    "🟢 Afficher l'indicateur vert",
    "🟢 Mostra Indicatore Verde",
    "🟢 緑のインジケーターを表示",
    "🟢 Toon groene indicator",
    "🟢 Mostrar Indicador Verde",
    "🟢 Показать зелёный индикатор"
};

const QStringList SHOW_GREEN_INDICATOR_HINT = {
    "Enables or disables display of the round green indicator.",
    "Aktiviert oder deaktiviert die Anzeige des runden grünen Indikators.",
    "Habilita o deshabilita la visualización del indicador verde redondo.",
    "Active ou désactive l'affichage de l'indicateur vert rond.",
    "Abilita o disabilita la visualizzazione dell'indicatore verde rotondo.",
    "丸い緑のインジケーターの表示を有効または無効にします。",
    "Schakelt de weergave van de ronde groene indicator in of uit.",
    "Ativa ou desativa a exibição do indicador verde arredondado.",
    "Включает или отключает отображение круглого зелёного индикатора."
};

const QStringList SHOW_GREEN_TEXT = {
    "Show Green Indicator Text",
    "Grünen Indikatortext anzeigen",
    "Mostrar texto del indicador verde",
    "Afficher le texte de l'indicateur vert",
    "Mostra testo indicatore verde",
    "緑のインジケーターテキストを表示",
    "Toon groene indicator tekst",
    "Mostrar Texto do Indicador Verde",
    "Показать зелёный индикаторный текст"
};

const QStringList SHOW_GREEN_TEXT_HINT = {
    "Enables or disables display of the space level text in the round green indicator.",
    "Aktiviert oder deaktiviert die Anzeige des Raumstufen-Textes im runden grünen Indikator.",
    "Habilita o deshabilita la visualización del texto del nivel de espacio en el indicador verde redondo.",
    "Active ou désactive l'affichage du texte du niveau d'espace dans l'indicateur rond vert.",
    "Abilita o disabilita la visualizzazione del testo del livello dello spazio nell'indicatore verde circolare.",
    "丸い緑のインジケーターにスペースレベルのテキストを表示するかどうかを有効または無効にします。",
    "Schakelt de weergave van de spatiëniveau-tekst in de ronde groene indicator in of uit.",
    "Habilita ou desabilita a exibição do texto do nível de espaço no indicador redondo verde.",
    "Включает или отключает отображение текста уровня пространства в круглой зелёной индикаторной панели."
};

const QStringList SHOW_YELLOW_INDICATOR = {
    "🟡 Show Yellow Indicator",
    "🟡 Gelben Indikator anzeigen",
    "🟡 Mostrar indicador amarillo",
    "🟡 Afficher l'indicateur jaune",
    "🟡 Mostra Indicatore Giallo",
    "🟡 黄色のインジケーターを表示",
    "🟡 Toon Gele Indicator",
    "🟡 Mostrar Indicador Amarelo",
    "🟡 Показать жёлтый индикатор"
};

const QStringList SHOW_YELLOW_INDICATOR_HINT = {
    "Enables or disables display of the round yellow indicator.",
    "Aktiviert oder deaktiviert die Anzeige des runden gelben Indikators.",
    "Habilita o deshabilita la visualización del indicador amarillo redondo.",
    "Active ou désactive l'affichage de l'indicateur jaune rond.",
    "Abilita o disabilita la visualizzazione dell'indicatore giallo rotondo.",
    "丸い黄色のインジケーターの表示を有効または無効にします。",
    "Schakelt de weergave van de ronde gele indicator in of uit.",
    "Ativa ou desativa a exibição do indicador amarelo redondo.",
    "Включает или отключает отображение круглого жёлтого индикатора."
};

const QStringList SHOW_YELLOW_AT_THRESHOLD = {
    "Show Yellow Indicator When",
    "Gelben Indikator anzeigen, wenn",
    "Mostrar indicador amarillo cuando",
    "Afficher l'indicateur jaune quand",
    "Mostra indicatore giallo quando",
    "表示する場合は黄色のインジケーター",
    "Geel indicator weergeven wanneer",
    "Mostrar indicador amarelo quando",
    "Показывать жёлтый индикатор, когда"
};

const QStringList SHOW_YELLOW_AT_THRESHOLD_HINT = {
    "Sets the threshold for the yellow warning indicator to come on.",
    "Legt die Schwelle fest, bei der die gelbe Warnanzeige aktiviert wird.",
    "Establece el umbral para que se encienda el indicador de advertencia amarillo.",
    "Définit le seuil pour que l'indicateur d'avertissement jaune s'allume.",
    "Imposta la soglia per l'accensione dell'indicatore di avviso giallo.",
    "黄色の警告インジケーターが点灯する閾値を設定します。",
    "Stelt de drempel in waarop het gele waarschuwingslampje gaat branden.",
    "Define o limite para que o indicador de aviso amarelo seja acionado.",
    "Устанавливает порог для включения желтого индикатора предупреждения."
};

const QStringList SHOW_YELLOW_TEXT = {
    "Show Yellow Indicator Text",
    "Gelben Indikatortext anzeigen",
    "Mostrar texto del indicador amarillo",
    "Afficher le texte de l'indicateur jaune",
    "Mostra testo indicatore giallo",
    "黄色のインジケーターテキストを表示",
    "Toon geel indicator tekst",
    "Mostrar Texto do Indicador Amarelo",
    "Показать текст жёлтого индикатора"
};

const QStringList SHOW_YELLOW_TEXT_HINT = {
    "Enables or disables display of the space level text in the round yellow indicator.",
    "Aktiviert oder deaktiviert die Anzeige des Raumleveltextes im runden gelben Indikator.",
    "Habilita o deshabilita la visualización del texto del nivel de espacio en el indicador amarillo redondo.",
    "Active ou désactive l'affichage du texte du niveau d'espace dans l'indicateur rond jaune.",
    "Abilita o disabilita la visualizzazione del testo del livello dello spazio nell'indicatore giallo rotondo.",
    "丸い黄色のインジケーターに表示される空間レベルのテキストの表示を有効または無効にします。",
    "Schakelt de weergave van de spatiëniveau-tekst in de ronde gele indicator in of uit.",
    "Habilita ou desabilita a exibição do texto do nível de espaço no indicador redondo amarelo.",
    "Включает или отключает отображение текста уровня пространства в круглой желтой индикации."
};

const QStringList SHOW_YELLOW_DIALOG = {
    "Show Yellow Indicator Dialog",
    "Gelbes Indikator-Dialogfeld anzeigen",
    "Mostrar diálogo de indicador amarillo",
    "Afficher la boîte de dialogue de l'indicateur jaune",
    "Mostra la finestra di dialogo dell'indicatore giallo",
    "黄色のインジケーターダイアログを表示",
    "Toon geel indicatorvenster",
    "Mostrar diálogo do indicador amarelo",
    "Показать диалог желтого индикатора"
};

const QStringList SHOW_YELLOW_DIALOG_HINT = {
    "Enables or disables display of the yellow warning dialog.",
    "Aktiviert oder deaktiviert die Anzeige des gelben Warnfensters.",
    "Habilita o deshabilita la visualización del cuadro de diálogo de advertencia amarillo.",
    "Active ou désactive l'affichage de la boîte de dialogue d'avertissement jaune.",
    "Abilita o disabilita la visualizzazione del dialogo di avviso giallo.",
    "黄色の警告ダイアログの表示を有効または無効にします。",
    "Schakelt de weergave van het gele waarschuwingsvenster in of uit.",
    "Ativa ou desativa a exibição da caixa de diálogo de aviso amarelo.",
    "Включает или отключает отображение желтого предупреждающего диалога."
};

const QStringList SHOW_RED_INDICATOR = {
    "🔴 Show Red Indicator",
    "🔴 Rote Anzeige anzeigen",
    "🔴 Mostrar indicador rojo",
    "🔴 Afficher l'indicateur rouge",
    "🔴 Mostra Indicatore Rosso",
    "🔴 赤のインジケーターを表示",
    "🔴 Toon Rode Indicator",
    "🔴 Mostrar Indicador Vermelho",
    "🔴 Показать красный индикатор"
};

/**
 * Settings hints.
 */
const QStringList SHOW_RED_INDICATOR_HINT = {
    "Enables or disables display of the round red indicator.",
    "Aktiviert oder deaktiviert die Anzeige des runden roten Indikators.",
    "Habilita o deshabilita la visualización del indicador rojo redondo.",
    "Active ou désactive l'affichage de l'indicateur rouge rond.",
    "Abilita o disabilita la visualizzazione dell'indicatore rosso rotondo.",
    "丸い赤いインジケーターの表示を有効または無効にします。",
    "Schakelt de weergave van de ronde rode indicator in of uit.",
    "Ativa ou desativa a exibição do indicador vermelho arredondado.",
    "Включает или отключает отображение круглого красного индикатора."
};

const QStringList SHOW_RED_AT_THRESHOLD = {
    "Show Red Indicator When",
    "Rote Anzeige anzeigen, wenn",
    "Mostrar indicador rojo cuando",
    "Afficher l'indicateur rouge lorsque",
    "Mostra indicatore rosso quando",
    "赤いインジケーターを表示する場合",
    "Toon rode indicator wanneer",
    "Mostrar indicador vermelho quando",
    "Показывать красный индикатор когда"
};

const QStringList SHOW_RED_AT_THRESHOLD_HINT = {
    "Sets the threshold for the red error indicator to come on.",
    "Legt die Schwelle fest, ab der die rote Fehleranzeige aktiviert wird.",
    "Establece el umbral para que se encienda el indicador de error rojo.",
    "Définit le seuil pour que l'indicateur d'erreur rouge s'allume.",
    "Imposta la soglia per l'accensione dell'indicatore di errore rosso.",
    "赤いエラーインジケーターが点灯する閾値を設定します。",
    "Stelt de drempel in waarop de rode foutindicator wordt geactiveerd.",
    "Define o limite para que o indicador de erro vermelho seja acionado.",
    "Устанавливает порог для включения индикатора красной ошибки."
};

const QStringList SHOW_RED_TEXT = {
    "Show Red Indicator Text",
    "Rote Indikatortext anzeigen",
    "Mostrar texto del indicador rojo",
    "Afficher le texte de l'indicateur rouge",
    "Mostra testo indicatore rosso",
    "赤いインジケーターテキストを表示",
    "Toon rode indicator tekst",
    "Mostrar Texto do Indicador Vermelho",
    "Показать красный индикаторный текст"
};

const QStringList SHOW_RED_TEXT_HINT = {
    "Enables or disables display of the space level text in the round red indicator.",
    "Aktiviert oder deaktiviert die Anzeige des Raumstufen-Textes im runden roten Indikator.",
    "Habilita o deshabilita la visualización del texto del nivel de espacio en el indicador redondo rojo.",
    "Active ou désactive l'affichage du texte du niveau d'espace dans l'indicateur rond rouge.",
    "Abilita o disabilita la visualizzazione del testo del livello dello spazio nell'indicatore rotondo rosso.",
    "赤い丸いインジケーターの中のスペースレベルのテキストの表示を有効または無効にします。",
    "Schakelt de weergave van de spatie-niveau tekst in de ronde rode indicator in of uit.",
    "Habilita ou desabilita a exibição do texto do nível de espaço no indicador redondo vermelho.",
    "Включает или отключает отображение текста уровня пространства в круглой красной индикации."
};

const QStringList SHOW_RED_DIALOG = {
    "Show Red Indicator Dialog",
    "Rotes Indikatorsdialogfeld anzeigen",
    "Mostrar diálogo de indicador rojo",
    "Afficher la boîte de dialogue de l'indicateur rouge",
    "Mostra la finestra di dialogo dell'indicatore rosso",
    "赤いインジケーターダイアログを表示",
    "Toon Rood Indicator Dialoog",
    "Mostrar diálogo do indicador vermelho",
    "Показать диалог с красным индикатором"
};

const QStringList SHOW_RED_DIALOG_HINT = {
    "Enables or disables display of the red warning dialog.",
    "Aktiviert oder deaktiviert die Anzeige des roten Warnfensters.",
    "Habilita o deshabilita la visualización del cuadro de diálogo de advertencia rojo.",
    "Active ou désactive l'affichage de la boîte de dialogue d'avertissement rouge.",
    "Abilita o disabilita la visualizzazione del dialogo di avviso rosso.",
    "赤い警告ダイアログの表示を有効または無効にします。",
    "Schakelt de weergave van het rode waarschuwingsvenster in of uit.",
    "Ativa ou desativa a exibição da caixa de diálogo de aviso vermelho.",
    "Включает или отключает отображение красного предупреждающего диалога."
};

const QStringList SHOW_TEXT_INDICATOR = {
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

const QStringList SHOW_TEXT_INDICATOR_HINT = {
    "Enables or disables display of the space level text.",
    "Aktiviert oder deaktiviert die Anzeige des Raum-Level-Textes.",
    "Habilita o deshabilita la visualización del texto del nivel de espacio.",
    "Active ou désactive l'affichage du texte du niveau d'espace.",
    "Abilita o disabilita la visualizzazione del testo del livello spaziale.",
    "スペースレベルのテキストの表示を有効または無効にします。",
    "Schakelt de weergave van de ruimteniveau-tekst in of uit.",
    "Ativa ou desativa a exibição do texto do nível de espaço.",
    "Включает или отключает отображение текста уровня пространства."
};

const QStringList INDICATOR_UPDATE_MINS = {
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

const QStringList INDICATOR_UPDATE_MINS_HINT = {
    "Sets duration between low space indicators and warnings checks.",
    "Legt die Dauer zwischen den Prüfungen von niedrigen Speicheranzeigen und Warnungen fest.",
    "Establece la duración entre los indicadores de espacio bajo y las comprobaciones de advertencias.",
    "Définit la durée entre les indicateurs d'espace faible et les vérifications des avertissements.",
    "Imposta la durata tra gli indicatori di spazio basso e i controlli degli avvisi.",
    "低スペースインジケーターと警告のチェック間の期間を設定します。",
    "Stelt de duur in tussen lage ruimte-indicatoren en waarschuwingscontroles.",
    "Define a duração entre os indicadores de pouco espaço e as verificações de alertas.",
    "Устанавливает длительность между проверками индикаторов низкого пространства и предупреждений."
};

const QStringList SHOW_ICON_INDICATOR = {
    "Show Icon when no Indicators",
    "Symbol anzeigen, wenn keine Indikatoren vorhanden sind",
    "Mostrar icono cuando no hay indicadores",
    "Afficher l'icône lorsqu'il n'y a pas d'indicateurs",
    "Mostra icona quando non ci sono indicatori",
    "インジケーターがないときにアイコンを表示",
    "Pictogram weergeven wanneer geen indicatoren",
    "Mostrar ícone quando não houver indicadores",
    "Показать значок, когда нет индикаторов"
};

const QStringList SHOW_ICON_INDICATOR_HINT = {
    "Enables or disables display of the widget icon when no indicator is otherwise displayed.",
    "Aktiviert oder deaktiviert die Anzeige des Widget-Symbols, wenn ansonsten kein Indikator angezeigt wird.",
    "Habilita o deshabilita la visualización del ícono del widget cuando no se muestra ningún indicador.",
    "Active ou désactive l'affichage de l'icône du widget lorsqu'aucun indicateur n'est affiché autrement.",
    "Abilita o disabilita la visualizzazione dell'icona del widget quando nessun indicatore è visualizzato.",
    "他のインジケーターが表示されていない場合に、ウィジェットアイコンの表示を有効または無効にします。",
    "Schakelt de weergave van het widgetpictogram in of uit wanneer er anders geen indicator wordt weergegeven.",
    "Habilita ou desabilita a exibição do ícone do widget quando nenhum indicador é exibido de outra forma.",
    "Включает или отключает отображение значка виджета, когда индикатор в противном случае не отображается."
};

const QStringList SHOW_SETTINGS_HINTS = {
    "Show Settings Hints",
    "Einstellungen Hinweise anzeigen",
    "Mostrar sugerencias de configuración",
    "Afficher les conseils des paramètres",
    "Mostra suggerimenti delle impostazioni",
    "設定のヒントを表示",
    "Toon instellingen tips",
    "Mostrar Dicas de Configurações",
    "Показать подсказки настроек"
};

const QStringList SHOW_SETTINGS_HINTS_HINT = {
    "Enables or disables display of these descriptions of settings on mouse hover.",
    "Aktiviert oder deaktiviert die Anzeige dieser Beschreibungen von Einstellungen beim Überfahren mit der Maus.",
    "Habilita o deshabilita la visualización de estas descripciones de configuraciones al pasar el ratón por encima.",
    "Active ou désactive l'affichage de ces descriptions des paramètres lors du survol de la souris.",
    "Abilita o disabilita la visualizzazione di queste descrizioni delle impostazioni al passaggio del mouse.",
    "マウスをホバーしたときに、これらの設定の説明の表示を有効または無効にします。",
    "Schakelt het weergeven van deze beschrijvingen van instellingen bij muisaanwijzer in- of uit.",
    "Ativa ou desativa a exibição dessas descrições das configurações ao passar o mouse.",
    "Включает или отключает отображение этих описаний настроек при наведении курсора мыши."
};

const QStringList SHOW_ICONS_ON_BUTTONS = {
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

const QStringList SHOW_ICONS_ON_BUTTONS_HINT = {
    "Enables or disables display of visual icons on buttons.",
    "Aktiviert oder deaktiviert die Anzeige von visuellen Symbolen auf Schaltflächen.",
    "Habilita o deshabilita la visualización de iconos visuales en los botones.",
    "Active ou désactive l'affichage des icônes visuelles sur les boutons.",
    "Abilita o disabilita la visualizzazione di icone visive sui pulsanti.",
    "ボタン上の視覚アイコンの表示を有効または無効にします。",
    "Schakelt de weergave van visuele pictogrammen op knoppen in of uit.",
    "Ativa ou desativa a exibição de ícones visuais nos botões.",
    "Включает или отключает отображение визуальных значков на кнопках."
};

/**
 * Third & final block, is all translation sets in a
 * searchable table for TranslationHelper.
 *
 * If you add a new language, you don't need to change this.
 */
const std::vector<QStringList> ALL_TRANSLATIONS = {

    /*
     * Second block - Dialog Headings, Buttons & Hints translations.
     */
    CONFIGURATION_TEXT, ABOUT_TEXT,
    RESET_TEXT, OK_TEXT, APPLY_TEXT, CANCEL_TEXT, REPO_TEXT,
    MINUTE, MINUTES,

    /*
     * Second block - Configuration Dialog translations.
     */
    APP_LANGUAGE, APP_LANGUAGE_HINT,

    INDICATOR_MARGIN_SIZE, INDICATOR_MARGIN_SIZE_HINT,
    INDICATOR_SHRINKS_TO_ROW, INDICATOR_SHRINKS_TO_ROW_HINT,
    INDICATOR_SIZE, INDICATOR_SIZE_HINT,
    INDICATOR_TEXT_SIZE, INDICATOR_TEXT_SIZE_HINT,

    SHOW_GREEN_INDICATOR, SHOW_GREEN_INDICATOR_HINT,
    SHOW_GREEN_TEXT, SHOW_GREEN_TEXT_HINT,

    SHOW_YELLOW_INDICATOR, SHOW_YELLOW_INDICATOR_HINT,
    SHOW_YELLOW_AT_THRESHOLD, SHOW_YELLOW_AT_THRESHOLD_HINT,
    SHOW_YELLOW_TEXT, SHOW_YELLOW_TEXT_HINT,
    SHOW_YELLOW_DIALOG, SHOW_YELLOW_DIALOG_HINT,

    SHOW_RED_INDICATOR, SHOW_RED_INDICATOR_HINT,
    SHOW_RED_AT_THRESHOLD, SHOW_RED_AT_THRESHOLD_HINT,
    SHOW_RED_TEXT, SHOW_RED_TEXT_HINT,
    SHOW_RED_DIALOG, SHOW_RED_DIALOG_HINT,

    SHOW_TEXT_INDICATOR, SHOW_TEXT_INDICATOR_HINT,

    INDICATOR_UPDATE_MINS, INDICATOR_UPDATE_MINS_HINT,

    SHOW_ICON_INDICATOR, SHOW_ICON_INDICATOR_HINT,
    SHOW_SETTINGS_HINTS, SHOW_SETTINGS_HINTS_HINT,
    SHOW_ICONS_ON_BUTTONS, SHOW_ICONS_ON_BUTTONS_HINT,

    /*
     * Second block - About Dialog translations.
     */
    ABOUT_DESCRIPTION, ABOUT_ARTWORK,

    /**
     * Second block - YellowDialog translations.
     */
    YELLOW_TITLE, YELLOW_WARNING,

    /**
     * Second block - RedDialog translations.
     */
    RED_TITLE, RED_ALERT

};

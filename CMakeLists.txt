##
# CMakeLists.txt to build plugin for LXQT panel.
#
set(APP_NAME "stoplight")

string(TOLOWER "${APP_NAME}" APP_ICON)
set(APP_ICON_PATH "share/icons/hicolor/scalable/apps")

set(APP_VERSION "26.08.27")
set(APP_VERSION_MINOR "02")

set(APP_AUTHOR "Mark James Capella")
set(ORG_NAME "skyrmion.inc")
set(SOURCE_REPO "https://github.com/markcapella/${APP_NAME}")

cmake_minimum_required(VERSION 3.18.0 FATAL_ERROR)
project(${APP_NAME})
include(GNUInstallDirs)

# Release optimization.
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

# Link-time optimization.
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

# Enable cmake.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Define escape codes for error messages.
string(ASCII 27 ESC)
set(COLOR_RED    "${ESC}[31m")
set(COLOR_GREEN  "${ESC}[32m")
set(COLOR_YELLOW "${ESC}[33m")
set(COLOR_NORMAL "${ESC}[m")

##
# Dependency Checking & Auto-APT Message Generator.
#
set(REQUIRED_QT_VERSION "6.6.0")
set(KF6_MINIMUM_VERSION "6.0.0")
set(LXQT_MINIMUM_VERSION "2.3.0")

# Detect Package Manager
find_program(DNF_CMD dnf)
find_program(APT_CMD apt-get)

if (DNF_CMD)
    set(PKG_INDEX "3")
    set(PKG_MGR_INSTALL "To fix, run:\n\n   sudo dnf install")
elseif (APT_CMD)
    set(PKG_INDEX "2")
    set(PKG_MGR_INSTALL "To fix, run:\n\n   sudo apt install")
else()
    set(PKG_INDEX "2")
    set(PKG_MGR_INSTALL
        "To fix, install with your package manager:\n\n   ")
endif()

# pkg-config is required by the dependency checker.
find_package(PkgConfig QUIET)

if (NOT PkgConfig_FOUND)
    set(STATUS0 "${COLOR_YELLOW}\nRequired build dependencies are missing.")
    message(NOTICE "${STATUS0}")
    if (DNF_CMD)
        set(STATUS1 "${COLOR_GREEN}Try: sudo dnf install")
        set(STATUS1 "${STATUS1} pkgconf-pkg-config${COLOR_NORMAL}")
        message(NOTICE "")
        message(NOTICE "${STATUS1}")
        message(NOTICE "")
        message(FATAL_ERROR "")
    elseif (APT_CMD)
        set(STATUS1 "${COLOR_GREEN}Try: sudo apt install")
        set(STATUS1 "${STATUS1} pkg-config${COLOR_NORMAL}")
        message(NOTICE "")
        message(NOTICE "${STATUS1}")
        message(NOTICE "")
        message(FATAL_ERROR "")
    else()
        set(STATUS1 "${COLOR_GREEN}Try installing pkg-config with")
        set(STATUS1 "${STATUS1} your package manager.${COLOR_NORMAL}")
        message(NOTICE "")
        message(NOTICE "${STATUS1}")
        message(NOTICE "")
        message(FATAL_ERROR "")
    endif()
endif()

set(MISSING_PACKAGES "")
set(DEPENDENCY_LIST
    "PROG|git|git|git"
    "PROG|make|build-essential|@development-tools"
    "CMAKE|Qt6Widgets|qt6-base-dev|qt6-qtbase-devel"
    "CMAKE|Qt6Xdg|libqt6xdg-dev|qt6-lxqt-devel"
    "CMAKE|KF6WindowSystem|libkf6windowsystem-dev|kf6-kwindowsystem-devel"
    "CMAKE|Qt6LinguistTools|qt6-l10n-tools|qt6-qttools-devel"
    "CMAKE|lxqt|liblxqt-dev|liblxqt-devel"
    "PROG|lxqt-panel|lxqt-panel|lxqt-panel"
)

foreach(ITEM IN LISTS DEPENDENCY_LIST)
    string(REPLACE "|" ";" ITEM_SPLIT "${ITEM}")
    list(GET ITEM_SPLIT 0 FIND_TYPE)
    list(GET ITEM_SPLIT 1 TARGET_NAME)
    list(GET ITEM_SPLIT ${PKG_INDEX} DISTRO_PKG)

    set(FOUND_FLAG FALSE)
    if (FIND_TYPE STREQUAL "PROG")
        find_program(PROG_PATH_${TARGET_NAME}
            ${TARGET_NAME}
            QUIET
        )
        if (PROG_PATH_${TARGET_NAME})
            set(FOUND_FLAG TRUE)
        endif()
    elseif (FIND_TYPE STREQUAL "CMAKE")
        find_package(${TARGET_NAME} QUIET)
        if (${TARGET_NAME}_FOUND OR ${${TARGET_NAME}_FOUND})
            set(FOUND_FLAG TRUE)
        endif()
    elseif (FIND_TYPE STREQUAL "PKG")
        pkg_check_modules(
            PKG_${TARGET_NAME}
            QUIET
            ${TARGET_NAME}
        )
        if (PKG_${TARGET_NAME}_FOUND)
            set(FOUND_FLAG TRUE)
        endif()
    endif()

    if (NOT FOUND_FLAG)
        list(APPEND MISSING_PACKAGES ${DISTRO_PKG})
    endif()
endforeach()

# Warn & stop with missing packages list.
if (MISSING_PACKAGES)
    list(REMOVE_DUPLICATES MISSING_PACKAGES)
    string(JOIN " " MISSING_PKG_STR ${MISSING_PACKAGES})

    set(STATUS0 "${COLOR_YELLOW}\nRequired build dependencies are missing.")
    message(NOTICE "${STATUS0}")

    set(STATUS2 "${COLOR_GREEN}${PKG_MGR_INSTALL} ${MISSING_PKG_STR}")
    set(STATUS2 "${STATUS2}${COLOR_NORMAL}")

    message(NOTICE "")
    message(NOTICE "${STATUS2}")
    message(NOTICE "")
    message(FATAL_ERROR "")
endif()

##
# Declare source code.
#
set(HEADERS
    StopLight.h StopLightView.h StopLightPluginLibrary.h
    ConfigDialog.h AboutDialog.h YellowDialog.h RedDialog.h
)

set(SOURCES
    StopLight.cpp StopLightView.cpp StopLightPluginLibrary.cpp
    ConfigDialog.cpp AboutDialog.cpp YellowDialog.cpp RedDialog.cpp
)

set(UIS ConfigDialog.ui)

set(PLUGIN ${APP_NAME})

include(LXQtTranslationLoader)
lxqt_plugin_translation_loader(QM_LOADER ${PLUGIN} "lxqt-panel")

add_library(${PLUGIN} MODULE
    ${HEADERS} ${SOURCES} ${UIS} ${QM_LOADER}
)

##
# Invoke i18n support.
#
qt_add_translations(${PLUGIN}
    TS_FILES
        translations/stoplight_de.ts
        translations/stoplight_es.ts
        translations/stoplight_fr.ts
        translations/stoplight_it.ts
        translations/stoplight_ja.ts
        translations/stoplight_nl.ts
        translations/stoplight_pt.ts
        translations/stoplight_ru.ts
    QM_FILES_OUTPUT_VARIABLE QM_FILES
)

##
# Install translations.
#
install(FILES ${QM_FILES}
    DESTINATION
        ${CMAKE_INSTALL_DATADIR}/lxqt/translations/lxqt-panel/${APP_ICON}
)

# Remove unused functions and data.
target_compile_options(${PLUGIN} PRIVATE
    -ffunction-sections
    -fdata-sections
)

target_link_options(${PLUGIN} PRIVATE
    -Wl,--gc-sections
)

##
# Create C++ Global #defines.
#
target_compile_definitions(${PLUGIN} PRIVATE
    APP_NAME="${APP_NAME}"
    APP_VERSION="${APP_VERSION}"
    APP_VERSION_MINOR="${APP_VERSION_MINOR}"
    APP_AUTHOR="${APP_AUTHOR}"
    ORG_NAME="${ORG_NAME}"
    SOURCE_REPO="${SOURCE_REPO}"
    APP_ICON="${APP_ICON}"
    APP_ICON_PATH="${CMAKE_INSTALL_PREFIX}/${APP_ICON_PATH}"
)

##
# Set plugin link library entries.
set(LIBRARIES Qt6Xdg)
target_link_libraries(${PLUGIN} Qt6::Widgets lxqt ${LIBRARIES}
    KF6::WindowSystem)

##
# Display leak report after app runs.
#
# Debug #1.
#
#target_compile_options(${PLUGIN} PRIVATE
#    -g -O1 -Wall -Wextra -Wuninitialized -Wmaybe-uninitialized
#)
#
# Debug #2 as Sanitizer build.
#
# Then use startPanelWithSanitizerBuild for debugging leaks.
#
#target_compile_options(${PLUGIN} PUBLIC
#    -g -O1 -fsanitize=address -fno-omit-frame-pointer)
#target_link_options(${PLUGIN} PUBLIC -fsanitize=address)

##
# Install plugin .desktop.
#
install(TARGETS ${PLUGIN}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/lxqt-panel
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET ${PLUGIN} POST_BUILD
        COMMAND ${CMAKE_STRIP} --strip-unneeded
            $<TARGET_FILE:${PLUGIN}>
    )
endif()

configure_file(resources/${APP_NAME}.desktop.in
    ${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.desktop @ONLY)

##
# Install plugin Icon.
#
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.desktop
    DESTINATION ${CMAKE_INSTALL_DATADIR}/lxqt/lxqt-panel)

install(FILES resources/${APP_ICON}.png DESTINATION
    ${CMAKE_INSTALL_DATADIR}/icons/hicolor/scalable/apps)

##
# Reset Lxqt panel, & FreeDesktop and XDG cache updates
# so the panel sees the changes immediately.
#
install(CODE "
    message(STATUS \"Updating icon and desktop caches...\")
    execute_process(COMMAND update-desktop-database)
    execute_process(COMMAND xdg-icon-resource forceupdate --theme hicolor)")

##
# Setup convenience target |make uninstall|.
#
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        @ONLY
    )

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND}
            -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    )
endif()

cmake_minimum_required(VERSION 3.16)
project(simpletextviewer LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)  # Habilita la generación automática de ui_*.h

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/assistant/simpletextviewer")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Incluye la ruta de los archivos de cabecera (en este caso, la raíz del proyecto)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

qt_add_executable(simpletextviewer
    main.cpp
    mainwindow.cpp mainwindow.h
    whiteboard.cpp whiteboard.h
    mainwindow.ui  # Asegúrate de que este archivo está en la misma carpeta
)

set_target_properties(simpletextviewer PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_compile_definitions(simpletextviewer PUBLIC
    SRCDIR="${CMAKE_CURRENT_SOURCE_DIR}/"
)

target_link_libraries(simpletextviewer PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

install(TARGETS simpletextviewer
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

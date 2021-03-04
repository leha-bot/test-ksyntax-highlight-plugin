cmake_minimum_required(VERSION 3.5)

project(test-ksyntax-highlight LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

add_library(test-syntax-highlight-plugin-interface INTERFACE)
target_sources(test-syntax-highlight-plugin-interface INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/SyntaxHighlightPlugin.h")

#
# plugins
#

# simplest from examples
add_library(test-syntax-highlight-example-plugin SHARED)
target_sources(test-syntax-highlight-example-plugin
    PRIVATE ExampleHighlighterPlugin.cpp ExampleHighlighterPlugin.h)
target_link_libraries(test-syntax-highlight-example-plugin PUBLIC Qt${QT_VERSION_MAJOR}::Widgets test-syntax-highlight-plugin-interface)

# based on KSyntaxHighlighting KF API.

find_package(KF5SyntaxHighlighting REQUIRED)

add_library(test-syntax-highlight-ksyntax-example-plugin SHARED)
target_sources(test-syntax-highlight-ksyntax-example-plugin
    PRIVATE ExampleHighlighterKSyntaxPlugin.cpp)
target_link_libraries(test-syntax-highlight-ksyntax-example-plugin PUBLIC Qt${QT_VERSION_MAJOR}::Widgets test-syntax-highlight-plugin-interface KF5::SyntaxHighlighting)


set(TS_FILES test-ksyntax-highlight_ru_RU.ts)

if(ANDROID)
  add_library(test-ksyntax-highlight SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
  )
else()
  add_executable(test-ksyntax-highlight
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
  )
endif()

target_link_libraries(test-ksyntax-highlight
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets test-syntax-highlight-plugin-interface)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

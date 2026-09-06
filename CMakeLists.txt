cmake_minimum_required(VERSION 3.16)
project(nega VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

qt_add_executable(nega MANUAL_FINALIZATION
    main.cpp
    firswindow.cpp firswindow.h firswindow.ui
    lhome.cpp lhome.h lhome.ui
    checkwindow.cpp checkwindow.h checkwindow.ui
    creet.cpp creet.h creet.ui
    qrc.qrc
    toastwidget.h toastwidget.cpp toastwidget.ui
)

target_link_libraries(nega PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    qscintilla2_qt6 # هنا ربطنا QScintilla
)

# مسار الهيدرات متاع QScintilla
target_include_directories(nega PRIVATE 
    /usr/include/x86_64-linux-gnu/qt6
)

qt_finalize_executable(nega)

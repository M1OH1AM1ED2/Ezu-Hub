cmake_minimum_required(VERSION 3.16)
project(Ezu-Hub VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network Multimedia)
find_package(SQLite3 REQUIRED)

qt_add_executable(Ezu-Hub MANUAL_FINALIZATION
    main.cpp
    firswindow.cpp firswindow.h firswindow.ui
    lhome.cpp lhome.h lhome.ui
    checkwindow.cpp checkwindow.h checkwindow.ui
    creet.cpp creet.h creet.ui
    qrc.qrc
    toastwidget.h toastwidget.cpp toastwidget.ui
    sqlite.h sqlite.cpp
    error.h error.cpp error.ui


)

target_link_libraries(Ezu-Hub PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    qscintilla2_qt6 
    SQLite::SQLite3
    Qt6::Multimedia

    
)

# مسار الهيدرات متاع QScintilla
target_include_directories(Ezu-Hub PRIVATE 
    /usr/include/x86_64-linux-gnu/qt6
)

qt_finalize_executable(Ezu-Hub)

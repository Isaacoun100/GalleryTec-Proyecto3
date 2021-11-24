cmake_minimum_required(VERSION 3.20)
project(GalleryTec_Proyecto3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}"${${PROJECT_NAME}_SOURCE_DIR}/cmake")

find_package( Qt5Core REQUIRED)
find_package( Qt5Widgets REQUIRED)
find_package( Qt5Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)

include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")

include_directories(GUI)
add_executable(GalleryTec_Proyecto3
        main.cpp
        GUI/GalleryTEC_GUI.h
        GUI/GalleryTEC_GUI.cpp
        GUI/MainApp.cpp
        GUI/MainApp.h
        Database_Management/UsersDatabaseHandler.cpp
        Database_Management/UsersDatabaseHandler.h)

target_link_libraries(GalleryTec_Proyecto3 Qt5::Widgets)
target_link_libraries(GalleryTec_Proyecto3 ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(GalleryTec_Proyecto3 ${LIBBSONCXX_LIBRARIES})
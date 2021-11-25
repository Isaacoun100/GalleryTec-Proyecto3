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

include_directories(GUI)

add_executable(GalleryTec_Proyecto3
        main.cpp
        GUI/GalleryTEC_GUI.h
        GUI/GalleryTEC_GUI.cpp
        GUI/MainApp.cpp
        GUI/MainApp.h
        MemoryManagement/FileHandler.cpp
        MemoryManagement/FileHandler.h
        GUI/MainApp.h
        local/ReadWrite.cpp
        local/ReadWrite.h huffman/HuffmanCompresion.cpp huffman/HuffmanCompresion.h ImageManagement/NewImage.cpp ImageManagement/NewImage.h)
target_link_libraries(GalleryTec_Proyecto3 Qt5::Widgets)

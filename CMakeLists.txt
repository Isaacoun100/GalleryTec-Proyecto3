cmake_minimum_required(VERSION 3.20)
project(GalleryTec_Proyecto3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}"${${PROJECT_NAME}_SOURCE_DIR}/cmake")
set(jsoncpp_lib_dir ${CMAKE_BINARY_DIR}/jsoncpp-build/src/lib_json)
set(jsoncpp_src_dir ${CMAKE_BINARY_DIR}/jsoncpp-src/include)

link_directories(jsoncpp_lib_dir)



find_package( Qt5Core REQUIRED)
find_package( Qt5Widgets REQUIRED)
find_package( Qt5Gui REQUIRED)
find_package(jsoncpp)

if (jsoncpp_found)
    message(STATUS "jsoncpp_include_dir:${jsoncpp_include_dir}")
    message(STATUS "jsoncpp_libraries:${jsoncpp_libraries}")
    message(STATUS "jsoncpp_version:${jsoncpp_version}")
endif ()

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
include_directories(jsoncpp_include_dir)

include_directories(GUI)
include_directories(Database_Management)
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
        local/ReadWrite.h
        huffman/HuffmanCompresion.cpp
        huffman/HuffmanCompresion.h
        ImageManagement/NewImage.cpp
        ImageManagement/NewImage.h
        GUI/MainApp.h
        GUI/SignInWindow.cpp
        GUI/SignInWindow.h
        GUI/MainApp.h
        Database_Management/UsersDatabaseHandler.cpp
        Database_Management/UsersDatabaseHandler.h
        Database_Management/MetadataDatabaseHandler.cpp
        Database_Management/MetadataDatabaseHandler.h)

target_link_libraries(GalleryTec_Proyecto3 Qt5::Widgets)
target_link_libraries(GalleryTec_Proyecto3 ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(GalleryTec_Proyecto3 ${LIBBSONCXX_LIBRARIES})
target_link_libraries(GalleryTec_Proyecto3 jsoncpp)

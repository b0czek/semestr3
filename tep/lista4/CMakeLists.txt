cmake_minimum_required(VERSION 3.25)
project(lista4)

set(CMAKE_CXX_STANDARD 98)


add_executable(lista4 main.cpp UserInterface.h)

add_subdirectory(CTree)
target_link_libraries(lista4 PUBLIC CTree)
target_include_directories(lista4 PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/CTree"
        )
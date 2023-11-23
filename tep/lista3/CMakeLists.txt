cmake_minimum_required(VERSION 3.25)
project(lista3)

set(CMAKE_CXX_STANDARD 98)


add_executable(lista3 main.cpp UserInterface.cpp UserInterface.h)

add_subdirectory(CTree)
target_link_libraries(lista3 PUBLIC CTree)
target_include_directories(lista3 PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/CTree"
        )
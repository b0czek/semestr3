cmake_minimum_required(VERSION 3.25)
project(lista3)

set(CMAKE_CXX_STANDARD 98)

add_library(CTree CNode.cpp CNode.h CTree.cpp CTree.h Operators.cpp Operators.h Parser.cpp Parser.h)

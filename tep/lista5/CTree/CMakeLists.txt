cmake_minimum_required(VERSION 3.25)
project(lista3)

set(CMAKE_CXX_STANDARD 11)

add_library(CTree CNode.h CTree.h Operators.h Parser.cpp Parser.h ParserParams/ParamsNumeric.h ParserParams/ParamsString.cpp ParserParams/ParamsString.h)

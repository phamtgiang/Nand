cmake_minimum_required(VERSION 3.15)
project(_assembler)

set(CMAKE_CXX_STANDARD 14)

add_executable(_assembler main.cpp symbol.cpp symbol.h parse.cpp parse.h translator.h translator.cpp)
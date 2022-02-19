cmake_minimum_required(VERSION 3.7)

add_library(lib_input_parser OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/InputParser.cpp)
add_library(lib_binary_input_parser OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/BinaryInputParser.cpp)

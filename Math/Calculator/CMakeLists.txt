cmake_minimum_required(VERSION 3.7)

add_library(lib_calculator OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/Calculator.cpp)
add_library(lib_binary_calculator OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/BinaryCalculator.cpp)

cmake_minimum_required(VERSION 3.7)

include("${CMAKE_SOURCE_DIR}/Gtest.cmake")

enable_testing()

add_subdirectory(router)
add_subdirectory(binary)
add_subdirectory(decimal)

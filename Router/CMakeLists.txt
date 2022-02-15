cmake_minimum_required(VERSION 3.7)

include("${CMAKE_SOURCE_DIR}/Rapidjson.cmake")

add_library(ROUTER SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Router.cpp)
target_link_libraries(ROUTER MATH)
add_dependencies(ROUTER rapidjson)

install(TARGETS ROUTER DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)

cmake_minimum_required(VERSION 3.7)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -pthread -fPIC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

project(calculator LANGUAGES CXX)

include_directories(Connection)
include_directories(Math)
include_directories(Router)

add_subdirectory(Connection)
add_subdirectory(Math)
add_subdirectory(Router)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME} MATH CONNECTION ROUTER)

if(${BUILD_TESTS})
	add_subdirectory(tests)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)

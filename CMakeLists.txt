cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -pthread -fPIC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

set(BOOST_INCLUDEDIR ${CMAKE_CURRENT_SOURCE_DIR}/boost_build/include)
set(BOOST_LIBRARYDIR ${CMAKE_CURRENT_SOURCE_DIR}/boost_build/lib)
find_package(Boost 1.77.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

project(calculator LANGUAGES CXX)

include_directories(Connection)
include_directories(Math/CalculationPipe)

add_subdirectory(Connection)
add_subdirectory(Math)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME} 
	MATH 
	CONNECTION 
	${Boost_LIBRARIES}
)

if(${BUILD_TESTS})
	add_subdirectory(googletest)
	enable_testing()
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
	add_subdirectory(tests)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})

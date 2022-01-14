cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -pthread -fPIC")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BOOST_INCLUDEDIR ${CMAKE_CURRENT_SOURCE_DIR}/boost_build/include)
set(BOOST_LIBRARYDIR ${CMAKE_CURRENT_SOURCE_DIR}/boost_build/lib)
find_package(Boost 1.77.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

project(calculator LANGUAGES CXX)

include_directories(Enums)
include_directories(Operand)
include_directories(Operation)
include_directories(Calculator)
include_directories(CalculationPipe)
include_directories(InputParser)
include_directories(InputDataConverter)
include_directories(Connection)

add_subdirectory(InputParser)
add_subdirectory(InputDataConverter)
add_subdirectory(Calculator)
add_subdirectory(CalculationPipe)
add_subdirectory(Operand)
add_subdirectory(Operation)
add_subdirectory(Connection)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_library(LIB_COMPONENTS STATIC
	$<TARGET_OBJECTS:lib_input_parser>
	$<TARGET_OBJECTS:lib_calculator>
	$<TARGET_OBJECTS:lib_calculation_pipe>
	$<TARGET_OBJECTS:lib_operand>
	$<TARGET_OBJECTS:lib_operation>
	$<TARGET_OBJECTS:lib_input_data_converter>
	$<TARGET_OBJECTS:lib_connection>
)

target_link_libraries(${PROJECT_NAME} LIB_COMPONENTS ${Boost_LIBRARIES})

if(${BUILD_TESTS})
	add_subdirectory(googletest)
	enable_testing()
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
	add_subdirectory(tests)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})

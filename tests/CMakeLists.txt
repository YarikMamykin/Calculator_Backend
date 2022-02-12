cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_SOURCE_DIR}/Math/InputParser)
include_directories(${CMAKE_SOURCE_DIR}/Math/InputDataConverter)
include_directories(${CMAKE_SOURCE_DIR}/Math/Calculator)
include_directories(${CMAKE_SOURCE_DIR}/Math/CalculationPipe)
include_directories(${CMAKE_SOURCE_DIR}/Math/Operation)
include_directories(${CMAKE_SOURCE_DIR}/Math/Operand)
include_directories(${CMAKE_SOURCE_DIR}/Math/Enums)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InputParserTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InputDataConverterTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CalculatorTest.cpp
)

add_executable(UNIT_TESTS ${SOURCES})

target_link_libraries(UNIT_TESTS  
	gtest 
	gmock
	gtest_main
	MATH
)

install(TARGETS UNIT_TESTS DESTINATION ${CMAKE_INSTALL_PREFIX})

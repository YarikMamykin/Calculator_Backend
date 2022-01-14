cmake_minimum_required(VERSION 3.0)

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
	LIB_COMPONENTS
)

install(TARGETS UNIT_TESTS DESTINATION ${CMAKE_INSTALL_PREFIX})

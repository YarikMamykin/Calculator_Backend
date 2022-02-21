cmake_minimum_required(VERSION 3.7)

add_executable(BINARY_UNIT_TESTS 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ParserTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CalculatorTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/PipeTest.cpp
)

target_link_libraries(BINARY_UNIT_TESTS  
	gtest 
	gmock
	gtest_main
	MATH
)

add_test(NAME BINARY_UNIT_TESTS COMMAND BINARY_UNIT_TESTS)

install(TARGETS BINARY_UNIT_TESTS DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/tests/)

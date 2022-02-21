cmake_minimum_required(VERSION 3.7)

add_executable(DECIMAL_UNIT_TESTS 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ParserTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/DataConverterTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CalculatorTest.cpp
)

target_link_libraries(DECIMAL_UNIT_TESTS  
	gtest 
	gmock
	gtest_main
	MATH
)

add_test(NAME DECIMAL_UNIT_TESTS COMMAND DECIMAL_UNIT_TESTS)

install(TARGETS DECIMAL_UNIT_TESTS DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/tests/)

cmake_minimum_required(VERSION 3.7)

add_executable(ROUTER_UNIT_TESTS 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/RouterTest.cpp
)

target_link_libraries(ROUTER_UNIT_TESTS  
	gtest 
	gmock
	gtest_main
	MATH
	ROUTER
)

add_test(NAME ROUTER_UNIT_TESTS COMMAND ROUTER_UNIT_TESTS)

install(TARGETS ROUTER_UNIT_TESTS DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/tests/)

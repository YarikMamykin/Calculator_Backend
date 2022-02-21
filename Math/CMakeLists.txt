cmake_minimum_required(VERSION 3.7)

include_directories(Pipe)

add_subdirectory(Decimal)
add_subdirectory(Binary)

add_subdirectory(Pipe)

add_library(MATH SHARED
	$<TARGET_OBJECTS:lib_decimal_parser>
	$<TARGET_OBJECTS:lib_decimal_calculator>
	$<TARGET_OBJECTS:lib_decimal_calculation_pipe>
	$<TARGET_OBJECTS:lib_decimal_operand>
	$<TARGET_OBJECTS:lib_decimal_operation>
	$<TARGET_OBJECTS:lib_decimal_data_converter>

	$<TARGET_OBJECTS:lib_binary_calculator>
	$<TARGET_OBJECTS:lib_binary_parser>
	$<TARGET_OBJECTS:lib_binary_calculation_pipe>

	$<TARGET_OBJECTS:lib_calculation_pipe>
)

install(TARGETS MATH DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)

cmake_minimum_required(VERSION 3.7)

include_directories(Enums)
include_directories(Operand)
include_directories(Operation)
include_directories(Calculator)
include_directories(CalculationPipe)
include_directories(InputParser)
include_directories(InputDataConverter)

add_subdirectory(InputParser)
add_subdirectory(InputDataConverter)
add_subdirectory(Calculator)
add_subdirectory(CalculationPipe)
add_subdirectory(Operand)
add_subdirectory(Operation)

add_library(MATH SHARED
	$<TARGET_OBJECTS:lib_input_parser>
	$<TARGET_OBJECTS:lib_calculator>
	$<TARGET_OBJECTS:lib_calculation_pipe>
	$<TARGET_OBJECTS:lib_operand>
	$<TARGET_OBJECTS:lib_operation>
	$<TARGET_OBJECTS:lib_input_data_converter>
	$<TARGET_OBJECTS:lib_binary_calculator>
	$<TARGET_OBJECTS:lib_binary_input_parser>
)

install(TARGETS MATH DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)

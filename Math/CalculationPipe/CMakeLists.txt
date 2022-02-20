cmake_minimum_required(VERSION 3.7)

add_library(lib_calculation_pipe OBJECT 
	${CMAKE_CURRENT_SOURCE_DIR}/CalculationPipe.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/DecimalCalculationPipe.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/BinaryCalculationPipe.cpp
)

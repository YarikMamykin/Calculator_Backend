cmake_minimum_required(VERSION 3.7)

include("${CMAKE_SOURCE_DIR}/Boost.cmake")

add_library(CONNECTION SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/Connection.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SyncWebsocketConnection.cpp
)

add_dependencies(CONNECTION boost)

target_link_libraries(CONNECTION ${Boost_LIBRARIES})

install(TARGETS CONNECTION DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)

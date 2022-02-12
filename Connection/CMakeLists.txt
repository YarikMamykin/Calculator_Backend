cmake_minimum_required(VERSION 3.7)

add_library(CONNECTION SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/Connection.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SyncWebsocketConnection.cpp
)

install(TARGETS CONNECTION DESTINATION ${CMAKE_INSTALL_PREFIX})

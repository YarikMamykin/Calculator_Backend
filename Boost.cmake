cmake_minimum_required(VERSION 3.7)

set(BOOST_INSTALL_DIR ${CMAKE_BINARY_DIR}/boost)

if(NOT DEFINED BOOST_BUILD_CPU_THREADS)
    set(BOOST_BUILD_CPU_THREADS 1)
endif()

include(ExternalProject)
ExternalProject_Add(
    boost
		URL https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.gz
    BUILD_IN_SOURCE 1
    CONFIGURE_COMMAND "./bootstrap.sh" --prefix=${BOOST_INSTALL_DIR} 
    BUILD_COMMAND "./b2" --disable-icu 
                         --with-system 
                         --with-thread 
                         --with-date_time 
                         --with-regex 
                         --with-serialization 
                         --link=shared 
                         -j ${BOOST_BUILD_CPU_THREADS} 
                         install 
    INSTALL_COMMAND ""
    INSTALL_DIR ${BOOST_INSTALL_DIR}
)

set(Boost_USE_STATIC_LIBS        OFF)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

set(BOOST_INCLUDEDIR ${BOOST_INSTALL_DIR}/include)
set(BOOST_LIBRARYDIR ${BOOST_INSTALL_DIR}/lib)
include_directories(${BOOST_INCLUDEDIR})

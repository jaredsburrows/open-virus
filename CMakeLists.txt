# COPYRIGHT (C) Jared Burrows 2015
# #
# Author: Jared Burrows <jaredsburrows@gmail.com>

cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)
project(OpenVirus)

# Set compiled binary path
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Make sure Boost is installed
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_definitions("-DHAS_BOOST")
endif()

add_subdirectory(client)
include_directories(client)

add_subdirectory(server)
include_directories(server)


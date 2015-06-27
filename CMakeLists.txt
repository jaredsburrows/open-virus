# Copyright (C) 2015 OpenVirus by Jared Burrows <jaredsburrows@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

message("== ====================================================")
message("== [OpenVirus - checking dependencies]")
message("== ====================================================")
message("")

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(OpenVirus C CXX)

# Debug
# -DCMAKE_CXX_COMPILER=
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Turn on C++ 11 support
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set paths
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Make sure Boost is installed
#find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIR})
#    add_definitions("-DHAS_BOOST")
#endif()



message("")
message("== ====================================================")
message("== [OpenVirus - setting flags]")
message("== ====================================================")
message("")

# All Warnings # -Werror -pedantic
set(WARNING_FLAGS "-Wall -Wextra ")

# Unsign/Sign and Signed Oveflow
#set(SIGNED_FLAGS "-Wconversion -Wsign-conversion -ftrapv ")

# Function format and Architecture
# 32 or 64? -arch x86_64
#set(FORMAT_FLAGS "-Wformat-security ")

# Stack protection
#set(STACK_FLAGS "-fstack-protector-all -Wstack-protector --param ssp-buffer-size=4 ")

# ASLR protection
##set(ASLR_FLAGS "-Wl,dynamicbase -pie -fPIE ")

# DEP protection
##set(DEP_FLAGS "-Wl,nxcompat ")

# All Security flags
#set(SECURITY_FLAGS "${SIGNED_FLAGS} ${FORMAT_FLAGS} ${STACK_FLAGS} ${OVERFLOW_FLAGS} ${ASLR_FLAGS} ${DEP_FLAGS} ")

set(SHARED_FLAGS "${WARNING_FLAGS} ${SECURITY_FLAGS}")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    message(STATUS "Using Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SHARED_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SHARED_FLAGS} -std=c++11 -stdlib=libc++ -ldl")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread -stdlib=libc++ -ldl")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "Using GCC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SHARED_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SHARED_FLAGS} -std=c++11 -pthread -ldl")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread -ldl")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "Using MSVC")
    add_definitions(
        /Wall
        /D "_CRT_SECURE_NO_WARNINGS"
    )
    # Enable multi-process compilation.
    if (NOT MSVC60 AND NOT MSVC70 AND NOT MSVC71)
        List(APPEND CFLAGS /MP)
    endif()
endif()



message("")
message("== ====================================================")
message("== [OpenVirus - building]")
message("== ====================================================")
message("")

# Common include directory
include_directories(include)

# Connect back for individual virus nodes
add_subdirectory(client)
include_directories(client)

# Virus node to be used on each individual computer
add_subdirectory(server)
include_directories(server)

# Individual modules to be loaded
add_subdirectory(modules)
include_directories(modules)

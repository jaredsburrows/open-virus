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

cmake_minimum_required (VERSION 2.8.7 FATAL_ERROR)
project(OpenVirus C CXX)

# Set compiled binary path
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

# Debugging
# set(SHARED_FLAGS "${WARNING_FLAGS}")

set(SHARED_FLAGS "${WARNING_FLAGS} ${SECURITY_FLAGS}")

# MSVC
if(MSVC OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC"
    OR "${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    message("-- Using MSVC")
    set(CMAKE_CXX_FLAGS "/W3")

    # Enable multi-process compilation.
    if(NOT MSVC60 AND NOT MSVC70 AND NOT MSVC71)
        List(APPEND CFLAGS /MP)
    endif()
endif()

# GCC
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"
    OR "${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    message("-- Using GCC")
    set(CMAKE_C_FLAGS "${SHARED_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")
    # set(CMAKE_EXE_LINKER_FLAGS, "-pthread")
endif()

# Clang
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
    OR "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_C_FLAGS "${SHARED_FLAGS}")
    set(CMAKE_CXX_FLAGS "${SHARED_FLAGS} -std=gnu++11 -stdlib=libc++")
    # set(CMAKE_EXE_LINKER_FLAGS, "-pthread")

    # Clang / Mac OS only
    if(APPLE)
        message("-- Using Clang on OSX")
        # Required on OSX to compile c++11
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmacosx-version-min=10.7")
    else()
        message("-- Using Clang")
    endif()
endif()

# Use Unicode by default on Windows target
if(WIN32)
    List(APPEND CFLAGS "${DEFINE}_UNICODE")
endif()



message("")
message("== ====================================================")
message("== [OpenVirus - building]")
message("== ====================================================")
message("")

add_subdirectory(client)
include_directories(client)

add_subdirectory(server)
include_directories(server)

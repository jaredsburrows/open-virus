cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

file(GLOB HELLO_SRC *.cpp)
file(GLOB HELLO_HEADERS *.hpp)

add_library(hello SHARED ${HELLO_SRC} ${HELLO_HEADERS})


cmake_minimum_required(VERSION 2.8.7)

file(GLOB HELLO_SRC *.cpp)
file(GLOB HELLO_HEADERS *.hpp)

add_library(hello SHARED ${HELLO_SRC} ${HELLO_HEADERS})


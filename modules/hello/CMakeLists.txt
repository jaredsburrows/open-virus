cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(HELLO_SRC
    "hello.hpp"
    "hello.cpp"
)

add_library(hello SHARED ${HELLO_SRC})


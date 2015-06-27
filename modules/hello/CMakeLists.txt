cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(SOURCE
    hello.hpp
    hello.cpp
)

add_library(hello SHARED ${SOURCE})


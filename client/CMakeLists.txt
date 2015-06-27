cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

file(GLOB client_SRC
    "*.h"
    "*.c"
)

add_executable(client ${client_SRC})


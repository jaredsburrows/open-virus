cmake_minimum_required(VERSION 2.8.12)

file(GLOB client_SRC
    "*.h"
    "*.c"
)

add_executable(client ${client_SRC})


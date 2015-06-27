cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

file(GLOB server_SRC
    "*.hpp"
    "*.cpp"
)

add_executable(server ${server_SRC})


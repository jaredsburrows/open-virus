cmake_minimum_required(VERSION 2.8.12)

file(GLOB server_SRC
    "*.hpp"
    "*.cpp"
)

add_executable(server ${server_SRC})


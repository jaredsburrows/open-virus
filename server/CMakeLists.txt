cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(SERVER_SRC
    "main.cpp"
    "shell.cpp"
)

add_executable(server ${SERVER_SRC})


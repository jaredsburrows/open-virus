cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CLIENT_SRC
    main.c
    network.c)

add_executable(client ${CLIENT_SRC})


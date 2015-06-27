cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(SOURCE
    main.c
    network.c)

add_executable(client ${SOURCE})


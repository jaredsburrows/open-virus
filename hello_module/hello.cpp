#include <iostream>

#include "hello.hpp"

std::string Hello::name() {
    return "Hello";
}

bool Hello::load() {

    return EXIT_SUCCESS;
}

bool Hello::unload() {

    return EXIT_SUCCESS;
}

void Hello::run() {
    // do something
}

void Hello::say() {
    std::cout << "Hello!" << std::endl;
}

extern "C" Module* load() {
    Module* module = new Hello;
    return module;
}

Module* load2() {
    Module* module = new Hello;
    return module;
}


#include <iostream>

#include "Hello.hpp"

std::string Hello::moduleName() {
    return "Hello";
}

int Hello::loadModule() {

    return EXIT_SUCCESS;
}

int Hello::unloadModule() {

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


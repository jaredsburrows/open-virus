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


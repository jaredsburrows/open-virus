#include <iostream>

#include <ov/server/shell.hpp>

const std::string Shell::runCommand(const char* command, const int size) {
    char* buffer = new char[size];
    std::string output = "";
    pipe = popen(command, "r");

    if (! pipe) {
        return "ERROR";
    }

    while (! feof(pipe)) {
        if (fgets(buffer, size, pipe) != NULL) {
            output += buffer;
        }
    }

    if (pipe) {
        pclose(pipe);
    }

    delete buffer;

    return output;
}

const std::string Shell::runCommand(const std::string command) {
    return Shell::runCommand(command.c_str());
}


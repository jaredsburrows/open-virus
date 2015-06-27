#ifndef SHELL_HPP
#define SHELL_HPP

class Shell {
private:
    FILE* pipe;
public:
    const std::string runCommand(const char* command, const int size = 128);
    const std::string runCommand(const std::string command);
};

#endif // SHELL_HPP


#ifndef HELLO_HPP
#define HELLO_HPP

#include <iostream>

#include "../Module.hpp"

class Hello : public Module {
public:
    virtual std::string moduleName();
    virtual int loadModule();
    virtual int unloadModule();
    virtual void run();
    void say();    
};

#endif // HELLO_HPP


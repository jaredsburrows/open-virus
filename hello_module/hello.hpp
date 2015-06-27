#ifndef HELLO_HPP
#define HELLO_HPP

#include <iostream>

#include <ov/module/module.hpp>

class Hello : public Module {
public:
    virtual std::string name();
    virtual bool load();
    virtual bool unload();
    virtual void run();
    void say();
};

#endif // HELLO_HPP


#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
 
class Module {
public:
    virtual std::string name() = 0;
    virtual bool load() = 0;
    virtual bool unload() = 0;
    virtual void run() = 0;
};
 
#endif // Module


#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
 
class Module {
public:
    virtual std::string moduleName() = 0;
    virtual int loadModule() = 0;
    virtual int unloadModule() = 0;
    virtual void run() = 0;
};
 
#endif // Module


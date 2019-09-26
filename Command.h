#ifndef _COMMAND_H_
#define _COMMAND_H_


#include <string>

class Command {
  public:
    virtual void execute() = 0;

    void printMessage(std::string aMessage);
};

#endif

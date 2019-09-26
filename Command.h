#ifndef _COMMAND_H_
#define _COMMAND_H_


#include <string>

class Command {
  public:
    virtual void execute() = 0;

    static void printMessage(const std::string& aMessage);
};

#endif

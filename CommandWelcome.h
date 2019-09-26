#ifndef _COMMAND_WELCOME_H_
#define _COMMAND_WELCOME_H_

#include "Command.h"

class CommandWelcome: public Command{
  public:
    void execute() override ;
};

#endif
#ifndef _COMMANDQUIT_H_
#define _COMMANDQUIT_H_

#include "Command.h"

class CommandQuit: public Command {
  public:
    void execute(std::string argument) override;
};


#endif

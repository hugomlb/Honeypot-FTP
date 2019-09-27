#ifndef _COMMAND_QUIT_H_
#define _COMMAND_QUIT_H_

#include "Command.h"

class CommandQuit: public Command {
  public:
    void execute(std::string argument) override;
};


#endif

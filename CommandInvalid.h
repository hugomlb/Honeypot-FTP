#ifndef _COMMAND_INVALID_H_
#define _COMMAND_INVALID_H_

#include "Command.h"

class CommandInvalid : public Command {
  public:
    void execute() override;
};


#endif

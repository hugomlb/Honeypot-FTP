#ifndef _COMMAND_QUIT_H_
#define _COMMAND_QUIT_H_

#include "Command.h"
#include "ServerConfiguration.h"

class CommandQuit: public Command {
  private:
    std::string quitSuccess;
  public:
    CommandQuit(ServerConfiguration* configuration);

    void execute(std::string argument) override;
};


#endif

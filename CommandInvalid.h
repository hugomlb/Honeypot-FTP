#ifndef _COMMAND_INVALID_H_
#define _COMMAND_INVALID_H_

#include "Command.h"
#include "ServerConfiguration.h"

class CommandInvalid : public Command {
  private:
    std::string unknownCommand;
  public:
    explicit CommandInvalid(ServerConfiguration* configuration);

    void execute(std::string argument, SocketPeer* socketPeer) override;
};

#endif

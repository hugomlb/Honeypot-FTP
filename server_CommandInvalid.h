#ifndef _COMMAND_INVALID_H_
#define _COMMAND_INVALID_H_

#include "server_Command.h"
#include "server_ServerConfiguration.h"

class server_CommandInvalid : public server_Command {
  private:
    std::string unknownCommand;
  public:
    explicit server_CommandInvalid(server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User *user,
                 common_SocketPeer* socketPeer) override;

    ~server_CommandInvalid();
};

#endif

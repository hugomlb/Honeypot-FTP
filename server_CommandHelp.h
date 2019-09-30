#ifndef _COMMAND_HELP_H_
#define _COMMAND_HELP_H_


#include <string>
#include "server_Command.h"
#include "server_User.h"

class server_CommandHelp: public server_Command {
  private:
    std::string commands;
    server_User* user;
  public:
    explicit server_CommandHelp(server_User* aUser,
        server_ServerConfiguration* configuration);

    void execute(std::string argument, common_SocketPeer* socketPeer) override;
};


#endif

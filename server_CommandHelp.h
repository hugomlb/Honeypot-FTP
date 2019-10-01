#ifndef _COMMAND_HELP_H_
#define _COMMAND_HELP_H_


#include <string>
#include "server_Command.h"
#include "server_User.h"

class server_CommandHelp: public server_Command {
  private:
    std::string commands;
  public:
    explicit server_CommandHelp(server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User* user,
                 common_SocketPeer* socketPeer) override;
};


#endif

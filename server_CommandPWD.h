#ifndef _COMMAND_PWD_H_
#define _COMMAND_PWD_H_

#include "server_Command.h"
#include "server_User.h"
#include "server_ServerConfiguration.h"

class server_CommandPWD: public server_Command {
  private:
    server_User* user;
    std::string currentDirectoryMsg;

    void currentDirectory(common_SocketPeer* socketPeer);
  public:
    explicit server_CommandPWD(server_User* aUser, server_ServerConfiguration* configuration);
    void execute(std::string argument, common_SocketPeer* socketPeer) override;
};


#endif

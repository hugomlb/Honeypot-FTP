#ifndef _COMMAND_USER_H_
#define _COMMAND_USER_H_

#include "server_Command.h"
#include "server_User.h"
#include "server_ServerConfiguration.h"
#include "common_SocketPeer.h"

class server_CommandUser: public server_Command {
  private:
    server_User* user;
    std::string passRequired;

  public:
    explicit server_CommandUser(server_User* aUser, server_ServerConfiguration* configuration);

    void execute(std::string argument, common_SocketPeer* socketPeer) override;
};


#endif

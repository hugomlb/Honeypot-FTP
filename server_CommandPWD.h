#ifndef _COMMAND_PWD_H_
#define _COMMAND_PWD_H_

#include "server_Command.h"
#include "server_User.h"
#include "server_ServerConfiguration.h"

class server_CommandPWD: public server_Command {
  private:
    std::string currentDirectoryMsg;

  public:
    explicit server_CommandPWD(server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User *user,
                 common_SocketPeer *socketPeer) override;
};


#endif

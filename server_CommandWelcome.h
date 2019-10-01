#ifndef _COMMAND_WELCOME_H_
#define _COMMAND_WELCOME_H_

#include "server_Command.h"
#include "server_ServerConfiguration.h"

class server_CommandWelcome: public server_Command{
  private:
    std::string newClient;
  public:
    explicit server_CommandWelcome(server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User* user,
                 common_SocketPeer* socketPeer) override ;

    ~server_CommandWelcome();
};

#endif
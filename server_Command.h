#ifndef _SERVER_COMMAND_H_
#define _SERVER_COMMAND_H_


#include <string>
#include "server_ServerConfiguration.h"
#include "common_SocketPeer.h"
#include "server_User.h"

class server_Command {
  private:
    std::string clientNotLogged;
  public:
    explicit server_Command(server_ServerConfiguration* configuration);

    virtual void execute(std::string argument, server_User *user,
                         common_SocketPeer *socketPeer) = 0;

    void askForLogin(common_SocketPeer* socketPeer);

    static void sendMessage(const std::string& aMessage,
        common_SocketPeer* socketPeer);

    ~server_Command() = default;
};

#endif

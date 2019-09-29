#ifndef _COMMAND_PASS_H_
#define _COMMAND_PASS_H_

#include "server_User.h"
#include "server_Command.h"
#include "server_ServerConfiguration.h"
#include "common_SocketPeer.h"

class server_CommandPass: public server_Command {
  private:
    server_User* user;
    std::string loginSuccess;
    std::string loginFailed;

    void sendLogState(int logState, common_SocketPeer* socketPeer);

  public:
    explicit server_CommandPass(server_User* aUser, server_ServerConfiguration* configuration);

    void execute(std::string argument, common_SocketPeer* socketPeer) override;
};

#endif

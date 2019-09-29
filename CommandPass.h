#ifndef _COMMAND_PASS_H_
#define _COMMAND_PASS_H_

#include "User.h"
#include "Command.h"
#include "ServerConfiguration.h"
#include "SocketPeer.h"

class CommandPass: public Command {
  private:
    User* user;
    std::string loginSuccess;
    std::string loginFailed;

    void sendLogState(int logState, SocketPeer* socketPeer);

  public:
    explicit CommandPass(User* aUser, ServerConfiguration* configuration);

    void execute(std::string argument, SocketPeer* socketPeer) override;
};

#endif

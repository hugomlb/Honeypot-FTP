#ifndef _COMMAND_SYST_H_
#define _COMMAND_SYST_H_

#include "Command.h"
#include "User.h"
#include "ServerConfiguration.h"
class CommandSyst: public Command {
  private:
    User* user;
    std::string systemInfo;

    void systemInformation();
  public:
    explicit CommandSyst(User* aUser, ServerConfiguration* configuration);

    void execute(std::string argument, SocketPeer* socketPeer) override;
};


#endif

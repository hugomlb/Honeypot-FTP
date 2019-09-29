#ifndef _COMMAND_SYST_H_
#define _COMMAND_SYST_H_

#include "server_Command.h"
#include "server_User.h"
#include "server_ServerConfiguration.h"
class server_CommandSyst: public server_Command {
  private:
    server_User* user;
    std::string systemInfo;

    void systemInformation(common_SocketPeer* socketPeer);
  public:
    explicit server_CommandSyst(server_User* aUser, server_ServerConfiguration* configuration);

    void execute(std::string argument, common_SocketPeer* socketPeer) override;
};


#endif

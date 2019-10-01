#ifndef _COMMAND_QUIT_H_
#define _COMMAND_QUIT_H_

#include "server_Command.h"
#include "server_ServerConfiguration.h"

class server_CommandQuit: public server_Command {
  private:
    std::string quitSuccess;
  public:
    server_CommandQuit(server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User *user,
                 common_SocketPeer *socketPeer) override;
};


#endif

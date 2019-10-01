#ifndef _COMMAND_RMD_H_
#define _COMMAND_RMD_H_

#include <string>
#include "server_User.h"
#include "server_ProtectedDirectorySet.h"
#include "server_Command.h"
#include "server_ServerConfiguration.h"

class server_CommandRMD: public server_Command {
  private:
    server_ProtectedDirectorySet* directories;
    std::string rmdSuccess;
    std::string rmdFailed;

  public:
    explicit server_CommandRMD(server_ProtectedDirectorySet* directorySet,
                               server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User *user,
                 common_SocketPeer *socketPeer) override ;
};


#endif

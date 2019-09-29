#ifndef _COMMAND_RMD_H_
#define _COMMAND_RMD_H_

#include <string>
#include "server_User.h"
#include "server_DirectorySet.h"
#include "server_Command.h"
#include "server_ServerConfiguration.h"

class server_CommandRMD: public server_Command {
  private:
    server_DirectorySet* directories;
    server_User* user;
    std::string rmdSuccess;
    std::string rmdFailed;

    void removeDirectory(const std::string& aDirectoryName, common_SocketPeer* socketPeer);

  public:
    explicit server_CommandRMD(server_DirectorySet* directorySet, server_User* aUser,
                               server_ServerConfiguration* configuration);

    void execute(std::string argument, common_SocketPeer* socketPeer) override ;
};


#endif

#ifndef _COMMAND_RMD_H_
#define _COMMAND_RMD_H_

#include <string>
#include "User.h"
#include "DirectorySet.h"
#include "Command.h"
#include "ServerConfiguration.h"

class CommandRMD: public Command {
  private:
    DirectorySet* directories;
    User* user;
    std::string rmdSuccess;
    std::string rmdFailed;

    void removeDirectory(const std::string& aDirectoryName);

  public:
    explicit CommandRMD(DirectorySet* directorySet, User* aUser,
                        ServerConfiguration* configuration);

    void execute(std::string argument, SocketPeer* socketPeer) override ;
};


#endif

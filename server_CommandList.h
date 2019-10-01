#ifndef _COMMAND_LIST_H_
#define _COMMAND_LIST_H_

#include "server_Command.h"
#include "server_User.h"
#include "server_ProtectedDirectorySet.h"
#include "server_ServerConfiguration.h"
#include "common_SocketPeer.h"

class server_CommandList: public server_Command {
  private:
    server_ProtectedDirectorySet* directories;
    std::string listBegin;
    std::string listEnd;
  public:
    explicit server_CommandList(server_ProtectedDirectorySet* directorySet,
        server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User *user,
                 common_SocketPeer* socketPeer) override;
};


#endif

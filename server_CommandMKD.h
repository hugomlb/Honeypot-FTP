#ifndef _COMMAND_MKD_H_
#define _COMMAND_MKD_H_

#include "server_Command.h"
#include "server_ProtectedDirectorySet.h"
#include "server_User.h"
#include "server_ServerConfiguration.h"
#include <string>

class server_CommandMKD: public server_Command {
  private:
    server_ProtectedDirectorySet* directories;
    std::string mkdSuccess;
    std::string mkdFailed;

  public:
    explicit server_CommandMKD(server_ProtectedDirectorySet* directorySet,
        server_ServerConfiguration* configuration);

    void execute(std::string argument, server_User *user,
                 common_SocketPeer *socketPeer) override;

    ~server_CommandMKD();
};


#endif

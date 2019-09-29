#ifndef _SERVER_CONNECTED_CLIENT_H_
#define _SERVER_CONNECTED_CLIENT_H_

#include <atomic>
#include "common_Thread.h"
#include "server_User.h"
#include "server_MapOfCommands.h"
#include "server_CommandWelcome.h"
#include "server_ClientProxy.h"

class server_ConnectedClient: public common_Thread {
  private:
    std::atomic<bool> isTalking{};
    server_User user;
    std::string lastCommandCode;
    server_MapOfCommands commands;
    server_ClientProxy clientProxy;

    server_Command* findCommand(std::string comandCode);
  public:
    server_ConnectedClient(server_ServerConfiguration* configuration,
        server_DirectorySet* directories, common_SocketPeer socketPeer);

    void welcomenClient(server_CommandWelcome* welcome);

    bool isDead();

    void run() override;
};


#endif
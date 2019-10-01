#ifndef _SERVER_CONNECTED_CLIENT_H_
#define _SERVER_CONNECTED_CLIENT_H_

#include <atomic>
#include "server_Thread.h"
#include "server_User.h"
#include "server_MapOfCommands.h"
#include "server_CommandWelcome.h"
#include "server_ComunicationProtocol.h"

class server_ClientProxy: public server_Thread {
  private:
    std::atomic<bool> isTalking{};
    server_User user;
    std::string lastCommandCode;
    server_MapOfCommands* commands;
    server_ComunicationProtocol comunicationProtocol;

    server_Command* findCommand(std::string comandCode);

    void communicate();
  public:
    server_ClientProxy(server_ServerConfiguration* configuration,
        server_MapOfCommands* mapOfCommands, common_SocketPeer socketPeer);

    void welcomenClient(server_CommandWelcome* welcome);

    void kill();

    bool isDead();

    void run() override;
};


#endif
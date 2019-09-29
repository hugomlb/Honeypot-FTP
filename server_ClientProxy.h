#ifndef _CLIENT_PROXY_H_
#define _CLIENT_PROXY_H_


#include "server_Server.h"

class server_ClientProxy {
  private:
    server_Server* server;
    common_SocketPeer socketPeer;

  public:
    explicit server_ClientProxy(server_Server* server, common_SocketPeer aSocketPeer);

    void receiveMessage(std::string* received);

    void decode(std::string command, std::string* comandCode, std::string* argument);

    void execute(server_Command* command, std::string argument);
};


#endif

#ifndef _CLIENT_PROXY_H_
#define _CLIENT_PROXY_H_


#include "Server.h"

class ClientProxy {
  private:
    Server* server;
    SocketPeer socketPeer;

  public:
    explicit ClientProxy(Server* server, SocketPeer aSocketPeer);

    void receiveMessage(std::string* received);

    void decode(std::string command, std::string* comandCode, std::string* argument);

    void execute(Command* command, std::string argument);
};


#endif

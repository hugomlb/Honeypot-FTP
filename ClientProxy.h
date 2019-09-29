#ifndef _CLIENT_PROXY_H_
#define _CLIENT_PROXY_H_


#include "Server.h"

class ClientProxy {
  private:
    Server* server;

  public:
    explicit ClientProxy(Server* server);
    void receiveMessage(SocketPeer* socketPeer);
};


#endif

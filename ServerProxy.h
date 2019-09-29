#ifndef _SERVER_PROXY_H_
#define _SERVER_PROXY_H_

#include "ClientProxy.h"
#include "SocketActive.h"

class ServerProxy {
  private:
    SocketActive socketActive;
  public:
    ServerProxy();

    void executeCommand(std::string aCommand);
};


#endif

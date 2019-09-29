#ifndef _SERVER_PROXY_H_
#define _SERVER_PROXY_H_

#include "server_ClientProxy.h"
#include "client_SocketActive.h"

class client_ServerProxy {
  private:
    SocketActive socketActive;

    std::string getAnswer();
  public:
    client_ServerProxy(const char* hostName, const char* service);

    void executeCommand(std::string aCommand);
};


#endif

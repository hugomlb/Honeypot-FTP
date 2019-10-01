#ifndef _SERVER_PROXY_H_
#define _SERVER_PROXY_H_

#include "server_ComunicationProtocol.h"
#include "client_SocketActive.h"
#include "client_ClientCommunicationProtocol.h"

class client_ServerProxy {
  private:
    client_ClientCommunicationProtocol communicationProtocol;

  public:
    client_ServerProxy(const char* hostName, const char* service);

    void executeCommand(std::string aCommand);

    ~client_ServerProxy();
};


#endif

#ifndef _SERVER_PROXY_H_
#define _SERVER_PROXY_H_

#include "ClientProxy.h"

class ServerProxy {
  private:
    ClientProxy clientProxy;
  public:
    void executeCommand(std::string aCommand);
};


#endif

#ifndef _SERVER_PROXY_H_
#define _SERVER_PROXY_H_


#include "Server.h"

class ServerProxy {
  private:
    Server server;
  public:
    void executeCommand(std::string aCommand);
};


#endif

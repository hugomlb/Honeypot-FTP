#ifndef _CLIENT_CLIENT_H_
#define _CLIENT_CLIENT_H_

#include "server_Server.h"
#include "client_ServerProxy.h"

class client_Client {
  private:
    client_ServerProxy serverProxy;
    
    void communicate();
  public:
    client_Client(const char* hostName, const char* service);

    void run();

    ~client_Client();
};


#endif
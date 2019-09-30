#ifndef _CLIENT_CLIENT_H_
#define _CLIENT_CLIENT_H_

#include "server_Server.h"

class client_Client {
  public:
    client_Client();

    static void run(const char* hostName, const char* service);

    ~client_Client();
};


#endif
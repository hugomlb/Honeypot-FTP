#ifndef _CONNECTED_CLIENT_VECTOR_H_
#define _CONNECTED_CLIENT_VECTOR_H_

#include <vector>
#include "server_ClientProxy.h"
#include "server_CommandWelcome.h"

class server_ClientProxyVector {
  private:
    std::vector<server_ClientProxy*> clients;
    server_CommandWelcome* welcome;
  public:
    explicit server_ClientProxyVector(server_CommandWelcome* command);

    void add(server_ClientProxy* client);

    void killAll();

    void clean();

    ~server_ClientProxyVector();
};


#endif

#ifndef _CONNECTED_CLIENT_VECTOR_H_
#define _CONNECTED_CLIENT_VECTOR_H_

#include <vector>
#include "server_ConnectedClient.h"
#include "server_CommandWelcome.h"

class server_ConnectedClientVector {
  private:
    std::vector<server_ConnectedClient*> clients;
    server_CommandWelcome* welcome;
  public:
    explicit server_ConnectedClientVector(server_CommandWelcome* command);

    void add(server_ConnectedClient* client);

    void killAll();

    ~server_ConnectedClientVector();
};


#endif

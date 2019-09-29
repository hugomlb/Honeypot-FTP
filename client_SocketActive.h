#ifndef _SOCKET_ACTIVE_H_
#define _SOCKET_ACTIVE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "common_SocketPeer.h"

class SocketActive: public common_SocketPeer {
  private:
    int getConnection(struct addrinfo* ptr);
  public:
    SocketActive();

    void connect(const char* hostName, const char* service);

    ~SocketActive();
};


#endif

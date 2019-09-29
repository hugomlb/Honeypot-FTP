#ifndef _SOCKET_ACTIVE_H_
#define _SOCKET_ACTIVE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "SocketPeer.h"

class SocketActive: public SocketPeer {
  private:
    int getConnection(struct addrinfo* ptr);
  public:
    SocketActive();

    void connect();

    ~SocketActive();
};


#endif

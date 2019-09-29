#ifndef _SOCKET_PASSIVE_H_
#define _SOCKET_PASSIVE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "SocketPeer.h"

class SocketPassive {
  private:
    int fd;

    int getBind(struct addrinfo* ptr);
  public:
    SocketPassive();

    void bind();

    void listen();

    SocketPeer acceptClient();

    ~SocketPassive();
};


#endif

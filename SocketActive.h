#ifndef _SOCKET_ACTIVE_H_
#define _SOCKET_ACTIVE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

class SocketActive {
  private:
    int fd;

    int getConnection(struct addrinfo* ptr);
  public:
    SocketActive();

    void connect();

    ~SocketActive();
};


#endif

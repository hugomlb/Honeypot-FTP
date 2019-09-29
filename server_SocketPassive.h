#ifndef _SOCKET_PASSIVE_H_
#define _SOCKET_PASSIVE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "common_SocketPeer.h"

class server_SocketPassive {
  private:
    int fd;

    int getBind(struct addrinfo* ptr);
  public:
    server_SocketPassive();

    void bind(const char *aService);

    void listen();

    common_SocketPeer acceptClient();

    void close();

    ~server_SocketPassive();
};


#endif

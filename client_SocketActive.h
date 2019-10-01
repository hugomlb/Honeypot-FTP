#ifndef _SOCKET_ACTIVE_H_
#define _SOCKET_ACTIVE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "common_SocketPeer.h"

class client_SocketActive: public common_SocketPeer {
  private:
    static int getConnection(struct addrinfo* ptr);

  public:
    client_SocketActive();

    void connect(const char* hostName, const char* service);

    ~client_SocketActive();
};


#endif

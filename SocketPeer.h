#ifndef _SOCKET_PEER_H_
#define _SOCKET_PEER_H_

#include <string>

class SocketPeer {
  private:
    int fd;
  public:
    explicit SocketPeer(int aFd);

    void send(std::string message);

    void receive(std::string* answer);

    ~SocketPeer();
};


#endif

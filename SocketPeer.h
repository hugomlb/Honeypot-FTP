#ifndef _SOCKET_PEER_H_
#define _SOCKET_PEER_H_

#include <string>

class SocketPeer {
  protected:
    int fd;
  public:
    explicit SocketPeer(int aFd);

    SocketPeer(SocketPeer&& other);

    SocketPeer& operator=(SocketPeer&& other);

    void send(std::string message);

    void receive(std::string* answer);

    ~SocketPeer();
};


#endif

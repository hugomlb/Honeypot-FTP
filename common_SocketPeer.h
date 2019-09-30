#ifndef _SOCKET_PEER_H_
#define _SOCKET_PEER_H_

#include <string>

class common_SocketPeer {
  protected:
    int fd;
  public:
    explicit common_SocketPeer(int aFd);

    common_SocketPeer(common_SocketPeer&& other);

    common_SocketPeer& operator=(common_SocketPeer&& other);

    void send(std::string message);

    void receive(std::string* answer);

    void close();

    ~common_SocketPeer();
};


#endif

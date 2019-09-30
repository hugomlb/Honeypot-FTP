#ifndef _COMMON_SOCKET_PEER_EXCEPTION_H_
#define _COMMON_SOCKET_PEER_EXCEPTION_H_

#include <stdexcept>

class common_SocketPeerException: public std::runtime_error {
  public:
    explicit common_SocketPeerException(const std::string &arg);
};


#endif

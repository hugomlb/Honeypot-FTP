#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include "client_SocketActive.h"
#include "common_SocketPeerException.h"

client_SocketActive::client_SocketActive(): common_SocketPeer(-1) {
}

void client_SocketActive::connect(const char* hostName, const char* service) {
  struct addrinfo hints;
  struct addrinfo *result;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  int errcheck = getaddrinfo(hostName, service, & hints, & result);
  if (errcheck != 0) {
    throw common_SocketPeerException("Imposible establecer conexion");
  }
  fd = getConnection(result);
  freeaddrinfo(result);
}

int client_SocketActive::getConnection(struct addrinfo *result) {
  int aFd = -1;
  bool connected = false;
  struct addrinfo *ptr;
  for (ptr = result; ptr != nullptr && !connected; ptr = ptr -> ai_next) {
    aFd = socket(ptr -> ai_family, ptr -> ai_socktype, ptr -> ai_protocol);
    if (aFd == -1) {
      throw common_SocketPeerException("FD Invalido");
    } else{
      int errcheck = ::connect(aFd, ptr -> ai_addr, ptr -> ai_addrlen);
      if (errcheck == -1) {
        ::close(aFd);
      }
      connected = (aFd != -1);
    }
  }
  return aFd;
}

client_SocketActive::~client_SocketActive() {
}

#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include "common_SocketPeer.h"
#include "common_SocketPeerException.h"

common_SocketPeer::common_SocketPeer(int aFd) {
  fd = aFd;
}

common_SocketPeer::common_SocketPeer(common_SocketPeer &&other) {
  this -> fd = other.fd;
  other.fd = -1;
}

common_SocketPeer &common_SocketPeer::operator=(common_SocketPeer &&other) {
  if (this == &other) {
    return *this;
  }
  this -> fd = other.fd;
  other.fd = -1;
  return *this;
}

void common_SocketPeer::send(std::string message) {
  int operationState;
  std::string::iterator iterator =  message.begin();
  char currentChar = *iterator;
  while (iterator != message.end()) {
    operationState = ::send(fd, (void*) &currentChar, 1, MSG_NOSIGNAL);
    if (operationState == 0) {
      throw common_SocketPeerException("Socket Closed");
    } else if (operationState == -1) {
      throw common_SocketPeerException("SOCKET CERRADO FORZOZAMENTE");
    }
    iterator ++;
    currentChar = *iterator;
  }
}

void common_SocketPeer::receive(std::string *answer) {
  int operationState;
  char currentChar = ' ';
  while (currentChar != '\n') {
    operationState = recv(fd, &currentChar, 1, 0);
    if (operationState == 0) {
      throw common_SocketPeerException("Socket Closed");
    } else if (operationState == -1) {
      //printf("Error: %s\n", strerror(errno));
      throw common_SocketPeerException("SOCKET CERRADO FORZOZAMENTE");
    }
    *answer += currentChar;
  }
}

void common_SocketPeer::close() {
  shutdown(fd, SHUT_RDWR);
  ::close(fd);
  fd = -1;
}

common_SocketPeer::~common_SocketPeer() {
  if (fd != -1) {
    close();
  }
}

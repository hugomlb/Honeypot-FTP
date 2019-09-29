#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include "common_SocketPeer.h"

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
  bool socketValid = true;
  std::string::iterator iterator =  message.begin();
  char currentChar = *iterator;
  while (iterator != message.end() && socketValid) {
    operationState = ::send(fd, (void*) &currentChar, 1, MSG_NOSIGNAL);
    if (operationState == 0) {
      socketValid = false;
      //returnValue = SOCKET_CLOSED;
    } else if (operationState == -1) {
      printf("Error: %s\n", strerror(errno));
      //returnValue = ERROR;
      socketValid = false;
    }
    iterator ++;
    currentChar = *iterator;
  }
}

void common_SocketPeer::receive(std::string *answer) {
  int operationState;
  bool socketValid = true;
  char currentChar = ' ';
  while (currentChar != '\n' && socketValid) {
    operationState = recv(fd, &currentChar, 1, 0);
    if (operationState == 0) {
      socketValid = false;
      //returnValue = SOCKET_CLOSED;
    } else if (operationState == -1) {
      printf("Error: %s\n", strerror(errno));
      //returnValue = ERROR;
      socketValid = false;
    }
    *answer += currentChar;
  }
}

common_SocketPeer::~common_SocketPeer() {
  if (fd != -1) {
    shutdown(fd, SHUT_RDWR);
    close(fd);
  }
}

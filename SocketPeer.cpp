#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include "SocketPeer.h"

SocketPeer::SocketPeer(int aFd) {
  fd = aFd;
}

void SocketPeer::send(std::string message) {
  int operationState;
  bool socketValid = true;
  std::string::iterator iterator =  message.begin();
  char currentChar = *iterator;
  do {
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
  } while (currentChar != '\n' && socketValid);
}

void SocketPeer::receive(std::string *answer) {
  int operationState;
  bool socketValid = true;
  char currentChar;
  do {
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
  } while (currentChar != '\n' && socketValid);
}

SocketPeer::~SocketPeer() {
  shutdown(fd, SHUT_RDWR);
  close(fd);
}

#include <netdb.h>
#include <cstring>
#include <cerrno>
#include <cstdio>
#include <unistd.h>
#include "client_SocketActive.h"

SocketActive::SocketActive(): common_SocketPeer(-1) {
}

void SocketActive::connect() {
  struct addrinfo hints;
  struct addrinfo *result;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  int errcheck = getaddrinfo("localhost", "7777", & hints, & result); //harcodeado
  if (errcheck != 0) {
    printf("Error in getaddrinfo: %s\n", gai_strerror(errcheck));
  }
  fd = getConnection(result);
  freeaddrinfo(result);
}

int SocketActive::getConnection(struct addrinfo *result) {
  int aFd = -1;
  bool connected = false;
  struct addrinfo *ptr;
  for (ptr = result; ptr != nullptr && !connected; ptr = ptr -> ai_next) {
    aFd = socket(ptr -> ai_family, ptr -> ai_socktype, ptr -> ai_protocol);
    if (aFd == -1) {
      printf("Error: %s\n", strerror(errno));
    } else{
      int errcheck = ::connect(aFd, ptr -> ai_addr, ptr -> ai_addrlen);
      if (errcheck == -1) {
        printf("Error: %s\n", strerror(errno));
        close(aFd);
      }
      connected = (aFd != -1);
    }
  }
  return aFd;
}

SocketActive::~SocketActive() {
  //shutdown(fd, SHUT_RDWR);
  //close(fd);
}

/*
int socketC_send(socketC_t *self, char *buf, int size) {
  int sent = 0;
  int s = 0;
  bool socketValid = true;
  int returnValue = OK;
  while (sent < size && socketValid) {
    s = send(self -> fd, &buf[sent], size - sent, MSG_NOSIGNAL);
    if (s == 0) {
      socketValid = false;
      returnValue = SOCKET_CLOSED;
    } else if (s == -1) {
      printf("Error: %s\n", strerror(errno));
      returnValue = ERROR;
      socketValid = false;
    }
    sent += s;
  }
  return returnValue;
}

int socketC_receive(socketC_t *self, char *buf, int size) {
  int received = 0;
  int s;
  bool socketValid = true;
  int returnValue = OK;
  while (received < size && socketValid) {
    s = recv(self -> fd, &buf[received], size - received, 0);
    if (s == 0) {
      socketValid = false;
      returnValue = SOCKET_CLOSED;
    } else if (s == -1) {
      printf("Error: %s\n", strerror(errno));
      returnValue = ERROR;
      socketValid = false;
    }
    received += s;
  }
  return returnValue;
}
*/

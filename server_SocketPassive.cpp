#include "server_SocketPassive.h"
#include "server_SocketPassiveException.h"
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <iostream>

server_SocketPassive::server_SocketPassive() {
  fd = -1;
}

void server_SocketPassive::bind(const char *aService) {
  struct addrinfo hints;
  struct addrinfo *rst;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int errCheck = getaddrinfo(nullptr, aService, &hints, &rst); //SERVICIO HARCODEADO*****************
  if (errCheck != 0) {
    printf("Error in getaddrinfo: %s\n", gai_strerror(errCheck));
  }
  fd = getBind(rst);
  freeaddrinfo(rst);
}

int server_SocketPassive::getBind(struct addrinfo *rst) {
  int aFd = -1;
  bool binded = false;
  struct addrinfo *ptr;
  for (ptr = rst; ptr != nullptr && !binded; ptr = ptr -> ai_next) {
    aFd = socket(ptr -> ai_family, ptr -> ai_socktype, ptr -> ai_protocol);
    if (aFd == -1) {
      printf("Error: %s\n", strerror(errno));
    }
    int val = 1;
    int errCheck = setsockopt(aFd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (errCheck == -1) {
      printf("Error: %s\n", strerror(errno));
      ::close(aFd);
    }
    errCheck = ::bind(aFd, ptr -> ai_addr, ptr -> ai_addrlen);
    if (errCheck == -1) {
      printf("Error: %s\n", strerror(errno));
      ::close(aFd);
    }
    binded = (errCheck != -1);
  }
  return aFd;
}

void server_SocketPassive::listen() {
  int errCheck = ::listen(fd, 1);
  if (errCheck == -1) {
    printf("Error: %s\n", strerror(errno));
  }
}

common_SocketPeer server_SocketPassive::acceptClient() {
  int aFd = accept(fd, nullptr, nullptr);
  if (aFd == -1) {
    throw server_SocketPassiveException("ACCEPT ERROR");
  }
  return std::move(common_SocketPeer(aFd));
}

server_SocketPassive::~server_SocketPassive() {
  if (fd != -1) {
    close();
  }
}

void server_SocketPassive::close() {
  shutdown(fd, SHUT_RDWR);
  ::close(fd);
  fd = -1;
}

#include "SocketPassive.h"
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <cstdio>
#include <cerrno>
#include <unistd.h>

SocketPassive::SocketPassive() {
  fd = -1;
}

void SocketPassive::bind() {
  struct addrinfo hints;
  struct addrinfo *ptr, *rst;
  bool binded = false;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int errCheck = getaddrinfo(NULL, "7777", &hints, &rst); //SERVICIO HARCODEADO*****************
  //leer man de getaddrinfo
  if (errCheck != 0) {
    printf("Error in getaddrinfo: %s\n", gai_strerror(errCheck));
  }
  int aFd = socket(rst -> ai_family, rst -> ai_socktype, rst -> ai_protocol);
  if (aFd == -1) {
    printf("Error: %s\n", strerror(errno));
  }
  int val = 1;
  errCheck = setsockopt(aFd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
  if (errCheck == -1) {
    printf("Error: %s\n", strerror(errno));
    close(aFd);
  }
  fd = aFd;
  for (ptr = rst; ptr != nullptr && !binded; ptr = ptr -> ai_next) {
    errCheck = ::bind(fd, ptr -> ai_addr, ptr -> ai_addrlen);
    //leer man de bind
    if (errCheck == -1) {
      printf("Error: %s\n", strerror(errno));
      close(errCheck);
    }
    binded = (errCheck != -1);
  }
  freeaddrinfo(rst);
}

void SocketPassive::listen() {
  int errCheck = ::listen(fd, 1);
  //leer man de listen
  if (errCheck == -1) {
    printf("Error: %s\n", strerror(errno));
  }
}

void SocketPassive::acceptClient() {
  fd = accept(fd, NULL, NULL);
  // leer man de accept
  if (fd == -1) {
    printf("Error: %s\n", strerror(errno));
  }
}

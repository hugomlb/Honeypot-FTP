#include <iostream>
#include <utility>
#include "server_Server.h"
#include "server_CommandWelcome.h"
#include "server_Command.h"
#include "server_ConnectedClient.h"


server_Server::server_Server(const char* aService, const char* configurationFile,
    server_SocketPassive* socketPassive): configuration(configurationFile), welcome(&configuration),
    clients(&welcome){
  this -> socketPassive = socketPassive;
  this -> socketPassive -> bind(aService);
  this -> socketPassive -> listen();
  keepRunning = false;
}

void server_Server::run() {
  keepRunning = true;
  server_CommandWelcome command(&configuration);
  while (keepRunning) {
    common_SocketPeer socketPeer = std::move(socketPassive -> acceptClient());
    if (keepRunning) {
      clients.add(new server_ConnectedClient(&configuration, &directories, std::move(socketPeer)));
    }
  }
}

void server_Server::stop() {
  keepRunning = false;
}

server_Server::~server_Server() {
}

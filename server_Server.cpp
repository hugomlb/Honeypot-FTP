#include <iostream>
#include <utility>
#include "server_Server.h"
#include "server_CommandWelcome.h"
#include "server_Command.h"
#include "server_ConnectedClient.h"
#include "server_SocketPassiveException.h"


server_Server::server_Server(const char* aService, const char* configurationFile,
    server_SocketPassive* aSocketPassive): configuration(configurationFile),
    welcome(&configuration), clients(&welcome) {
  this -> socketPassive = aSocketPassive;
  this -> socketPassive -> bind(aService);
  this -> socketPassive -> listen();
  keepRunning = false;
}

void server_Server::run() {
  keepRunning = true;
  server_CommandWelcome command(&configuration);
  while (keepRunning) {
    try {
      common_SocketPeer socketPeer = std::move(socketPassive -> acceptClient());
      if (keepRunning) {
        clients.add(new server_ConnectedClient(&configuration, &directories, std::move(socketPeer)));
      }
    } catch (server_SocketPassiveException &e) {
      keepRunning = false;
    }
  }
}

void server_Server::stop() {
  keepRunning = false;
}

server_Server::~server_Server() {
}

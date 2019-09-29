#include <iostream>
#include <utility>
#include "server_Server.h"
#include "server_CommandWelcome.h"
#include "server_Command.h"
#include "server_ConnectedClient.h"
#include "server_ConnectedClientVector.h"


server_Server::server_Server(const char* aService, const char* configurationFile):
    configuration(configurationFile) {
  socketPassive.bind(aService);
  socketPassive.listen();
  keepRunning = false;
}

void server_Server::run() {
  keepRunning = true;
  server_CommandWelcome command(&configuration);
  server_ConnectedClientVector clients(&command);
  while (keepRunning) {
    common_SocketPeer socketPeer = std::move(socketPassive.acceptClient());
    clients.add(new server_ConnectedClient(&configuration, &directories, std::move(socketPeer)));
  }
}

void server_Server::stop() {
  keepRunning = false;
}

server_Server::~server_Server() {
}

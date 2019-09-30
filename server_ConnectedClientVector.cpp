#include <iostream>
#include "server_ConnectedClientVector.h"

server_ConnectedClientVector::server_ConnectedClientVector(
    server_CommandWelcome *command) {
  welcome = command;
}

void server_ConnectedClientVector::add(server_ConnectedClient *client) {
  client -> welcomenClient(welcome);
  client -> start();
  clients.push_back(client);
}

void server_ConnectedClientVector::killAll() {
  int i = 0;
  while(!clients.empty()) {
    if (!clients[i] -> isDead()) {
      clients[i] -> kill();
    }
    clients[i] -> join();
    delete clients[i];
    clients.erase(clients.begin());
  }
}

server_ConnectedClientVector::~server_ConnectedClientVector() {
  if (!clients.empty()) {
    for (int i = 0; i < (int) clients.size(); i++) {
      clients[i] -> join();
      delete clients[i];
    }
  }
}

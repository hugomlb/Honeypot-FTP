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

server_ConnectedClientVector::~server_ConnectedClientVector() {
  for (int i = 0; i < (int) clients.size(); i++) {
    clients[i] -> join();
    delete clients[i];
  }
}

void server_ConnectedClientVector::kill() {
}

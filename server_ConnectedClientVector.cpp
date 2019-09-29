#include "server_ConnectedClientVector.h"

server_ConnectedClientVector::server_ConnectedClientVector(
    server_CommandWelcome *command) {
  welcome = command;
}

void server_ConnectedClientVector::add(server_ConnectedClient *client) {
  client -> welcomenClient(welcome);
  client -> run();
  clients.push_back(client);
}

server_ConnectedClientVector::~server_ConnectedClientVector() {
  for (unsigned long i = 0; i < clients.size(); i++) {
    clients[i] -> join();
    delete clients[i];
  }
}

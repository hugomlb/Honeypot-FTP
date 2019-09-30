#include <iostream>
#include "server_ClientProxyVector.h"

server_ClientProxyVector::server_ClientProxyVector(
    server_CommandWelcome *command) {
  welcome = command;
}

void server_ClientProxyVector::add(server_ClientProxy *client) {
  client -> welcomenClient(welcome);
  client -> start();
  clients.push_back(client);
}

void server_ClientProxyVector::killAll() {
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

server_ClientProxyVector::~server_ClientProxyVector() {
  if (!clients.empty()) {
    for (int i = 0; i < (int) clients.size(); i++) {
      clients[i] -> join();
      delete clients[i];
    }
  }
}

void server_ClientProxyVector::clean() {
  //std::vector<server_ClientProxy*>::iterator iterator = std::find_if(clients.begin(), clients.end(), );
}

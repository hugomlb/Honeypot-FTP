#include "client_Client.h"
#include "client_ServerProxy.h"
#include <iostream>

client_Client::client_Client() {
}

void client_Client::run(const char* hostName, const char* service) {
  client_ServerProxy server(hostName, service);
  std::string command = " ";
  while (command != "QUIT" ) {
    getline(std::cin, command);
    server.executeCommand(command);
  }
}

client_Client::~client_Client() {
}

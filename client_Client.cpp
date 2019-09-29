#include "client_Client.h"
#include "client_ServerProxy.h"
#include <iostream>

void client_Client::run() {
  client_ServerProxy server;
  std::string command = " ";
  while (command != "QUIT" ) {
    getline(std::cin, command);
    server.executeCommand(command);
  }
}

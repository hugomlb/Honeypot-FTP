#include "Client.h"
#include "ServerProxy.h"
#include <iostream>

void Client::run() {
  ServerProxy server;
  std::string command = " ";
  while (command != "QUIT" ) {
    getline(std::cin, command);
    server.executeCommand(command);
  }
}

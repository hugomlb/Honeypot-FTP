#include "Client.h"
#include <iostream>

void Client::run() {
  Server server;
  server.newClient();
  std::string command = " ";
  while (command.compare("QUIT") != 0 ) {
    getline(std::cin, command);
    server.executeCommand(command);
  }
}

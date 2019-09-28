#include "Client.h"
#include <iostream>

void Client::run() {
  Server server;
  std::string command = " ";
  while (command != "QUIT" ) {
    getline(std::cin, command);
    server.executeCommand(command);
  }
}
//PAra la parte de comunicacion fijarse que se esten mandando los \n

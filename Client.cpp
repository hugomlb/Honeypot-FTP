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
//PAra la parte de comunicacion fijarse que se esten mandando los \n
//PREGUNTAR SOBRE EL ARCHIVO SI TIENE UN NOMBRE FIJO
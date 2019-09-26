#include "Client.h"
#include <iostream>

void Client::run() {
  Server server;
  server.newClient();
  std::string command;
  getline(std::cin, command);
  std::cout << "331 Please specify the password." << std::endl;
  getline(std::cin, command);
  if (command.compare(0, 5, "PASS ") == 0) {
    server.userLogin(command.substr(5, std::string::npos));
  } else {
    server.invalidCommand();
  }
  while (command.compare("QUIT") != 0 ) {
    getline(std::cin, command);
    server.mkd(command);
  }
  server.quit();
}

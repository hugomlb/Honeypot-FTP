#include <iostream>
#include <sstream>
#include "Server.h"
#include "CommandWelcome.h"
#include "Command.h"

Server::Server() : user(&configuration), commands(&user, &directories,
    &configuration) {
  CommandWelcome command(&configuration);
  command.execute("");
}

void Server::executeCommand(const std::string& command) {
  std::string commandCode;
  std::string commandArgument;
  if (command.find_first_of(' ') != std::string::npos) {
    std::istringstream test(command);
    getline(test, commandCode, ' ');
    getline(test, commandArgument);
  } else {
    commandCode = command;
  }
  commands.findAndExecute(commandCode, commandArgument);
  user.lastCommandWas(commandCode);
}

Server::~Server() {
}

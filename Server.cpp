#include <iostream>
#include <sstream>
#include "Server.h"
#include "CommandWelcome.h"
#include "CommandInvalid.h"


Server::Server() : user("hugo", "hola"), list(&directories, &user), make(&directories, &user),
    remove(&directories, &user), userLog(&user), passLog(&user) {
  commandMap["LIST"] = &list;
  commandMap["QUIT"] = &quit;
  commandMap["MKD"] = &make;
  commandMap["RMD"] = &remove;
  commandMap["USER"] = &userLog;
  commandMap ["PASS"] = &passLog;
}

void Server::newClient() {
  CommandWelcome command;
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

  auto iterator = commandMap.find(commandCode);
  if (iterator != commandMap.end()) {
    iterator -> second -> execute(commandArgument);
  } else {
    CommandInvalid commandInvalid;
    commandInvalid.execute("");
  }
  user.lastCommandWas(commandCode);
}

Server::~Server() {
}

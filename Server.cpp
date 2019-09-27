#include <iostream>
#include <sstream>
#include "Server.h"
#include "CommandRMD.h"
#include "CommandWelcome.h"
#include "CommandInvalid.h"
#include "CommandMKD.h"

Server::Server() : user("hugo", "hola"), list(&directories), make (&directories),
    remove(&directories), userLog(&user), passLog(&user) {
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

/*
void Server::list() {
  if (user.isLogged()) {
    CommandList command(&directories);
    command.execute();
  }
}
*/
/*
void Server::mkd(const std::string& aDirectoryName) {
  if (user.isLogged()) {
    CommandMKD command(&directories);
    command.execute(aDirectoryName);
  }
}

void Server::rmd(const std::string& aDirectoryName) {
  if (user.isLogged()) {
    CommandRMD command(&directories);
    command.execute(aDirectoryName);
  }
}
*/
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

#include <iostream>
#include <sstream>
#include "Server.h"
#include "CommandRMD.h"
#include "CommandWelcome.h"
#include "CommandInvalid.h"
#include "CommandMKD.h"

Server::Server() : user("hugo", "hola"), list(&directories), make (&directories)
  , remove(&directories){
  commandMap["LIST"] = &list;
  commandMap["QUIT"] = &quit;
  commandMap["MKD"] = &make;
  commandMap["RMD"] = &remove;
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
  std::istringstream test(command);
  if (command.find_first_of(' ') != std::string::npos) {
    getline(test, commandCode, ' ');
    getline(test, commandArgument);
  } else {
    commandCode = command;
  }
  user.isLogged();
  user.enterPassword("hola");
  user.isLogged();
  user.enterUserName("hugo");
  user.lastCommandWas("USER");
  user.enterPassword("hola");
  user.isLogged();
  /*
  auto iterator = commandMap.find(commandCode);
  if (iterator != commandMap.end()) {
    iterator -> second -> execute(commandArgument);
  } else {
    CommandInvalid commandInvalid;
    commandInvalid.execute("");
  }
   */
}

Server::~Server() {
}

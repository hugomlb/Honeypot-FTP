#include "Server.h"
#include "DirectorySetException.h"
#include "CommandRMD.h"
#include "CommandWelcome.h"
#include "CommandInvalid.h"
#include "CommandQuit.h"
#include "CommandList.h"
#include "CommandMKD.h"

Server::Server() : user("hugo", "hola") {
}

void Server::newClient() {
  CommandWelcome command;
  command.execute();
}

void Server::userLogin(const std::string& password) {
  user.login(password);
}

void Server::invalidCommand() {
  CommandInvalid command;
  command.execute();
}

void Server::list() {
  if (user.isLogged()) {
    CommandList command(&directories);
    command.execute();
  }
}

void Server::mkd(const std::string& aDirectoryName) {
  if (user.isLogged()) {
    CommandMKD command(aDirectoryName, &directories);
    command.execute();
  }
}

void Server::rmd(const std::string& aDirectoryName) {
  if (user.isLogged()) {
    CommandRMD command(aDirectoryName, &directories);
    command.execute();
  }
}

void Server::quit() {
  CommandQuit command;
  command.execute();
}

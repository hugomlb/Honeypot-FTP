#include "Server.h"
#include "DirectorySetException.h"
#include <iostream>
#include "CommandWelcome.h"
#include "CommandInvalid.h"
#include "CommandQuit.h"
#include "CommandList.h"

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
    try {
      directories.addDirectory(aDirectoryName);
      std::cout << "257 " << aDirectoryName << " created" << std::endl;
    } catch (DirectorySetException &e) {
      std::cout << "550 Create directory operation failed." << std::endl;
    }
  }
}

void Server::rmd(const std::string& aDirectoryName) {
  if (user.isLogged()) {
    try {
      directories.removeDirectory(aDirectoryName);
      std::cout << "250 Remove directory operation successful." << std::endl;
    } catch (DirectorySetException &e) {
      std::cout << "550 Remove directory operation failed.";
    }
  }
}

void Server::quit() {
  CommandQuit command;
  command.execute();
}

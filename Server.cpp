#include "Server.h"
#include "DirectorySetException.h"
#include <iostream>

Server::Server() : user("hugo", "hola") {
}


void Server::newClient() {
  std::cout << "230 TallerFTP" << std::endl;
}

void Server::userLogin(const std::string& password) {
  user.login(password);
}


void Server::invalidCommand() {
  std::cout << "500 Unknown command." << std::endl;
}

void Server::list() {
  if (user.isLogged()) {
    std::cout << "150 Here comes the directory listing." << std::endl;
    if (!directories.isEmpty()) {
      std::cout << "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 <nombreDelDirectorio>" << std::endl;
    }
    std::cout << "226 Directory send OK." << std::endl;
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
  std::cout << "221 Goodbye." << std::endl;
}

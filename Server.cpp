#include "Server.h"
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
    //IMPRIMIR LA LISTA DE DIRECTORIOS EN ORDEN ALFABETICO
    std::cout << "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 <nombreDelDirectorio>" << std::endl;
    std::cout << "226 Directory send OK." << std::endl;
  }
}

void Server::mkd(std::string aDirectoryName) {
  if (user.isLogged()) {
    //Si el directorio ya esta creado imprimir "550 Create directory operation failed."
    std::cout << "257 " << aDirectoryName << "created" << std::endl;
  }
}

void Server::rmd(std::string aDirectoryName) {
  if (user.isLogged()) {
    //SI el directorio existe
    std::cout << "250 Remove directory operation successful." << std::endl;
    //SI EL DIRECTORIO NO EXISTE
    std::cout << "550 Remove directory operation failed.";
  }
}

void Server::quit() {
  std::cout << "221 Goodbye." << std::endl;
}

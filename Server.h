#ifndef _SERVER_H_
#define _SERVER_H_

#include <string>
#include <unordered_map>
#include "User.h"
#include "DirectorySet.h"
#include "MapOfCommands.h"

class Server {
  //Al recibir una 'q' de entrada standar, el servidor debe cerrarse
  /*
   * PREGUNTAR:
   *  Ejemplo de help
   *  Cuestiones de como es la comunicacion por sockets (del servidor al cliente)
   */
  private:
    ServerConfiguration configuration;
    User user;
    DirectorySet directories;
    MapOfCommands commands;

   // void help(); //Consultar

  public:
    Server();

    void executeCommand(const std::string& command);

    ~Server();
};

#endif

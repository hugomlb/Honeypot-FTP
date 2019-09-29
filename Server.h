#ifndef _SERVER_H_
#define _SERVER_H_

#include <string>
#include <unordered_map>
#include "User.h"
#include "DirectorySet.h"
#include "MapOfCommands.h"
#include "SocketPassive.h"

class Server {
  //Al recibir una 'q' de entrada standar, el servidor debe cerrarse
  /*
   * PREGUNTAR:
   *  Cuestiones de como es la comunicacion por sockets (del servidor al cliente)
   */
  private:
    ServerConfiguration configuration;
    User user;
    DirectorySet directories;
    MapOfCommands commands;
    SocketPassive socketPassive;
    std::string lastCommandCode;


  public:
    Server();

    void run();

    void executeCommand(const std::string& commandCode, std::string argument);

    ~Server();
};

#endif

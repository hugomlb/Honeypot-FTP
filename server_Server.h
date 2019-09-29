#ifndef _SERVER_SERVER_H_
#define _SERVER_SERVER_H_

#include <string>
#include <unordered_map>
#include "server_User.h"
#include "server_DirectorySet.h"
#include "server_MapOfCommands.h"
#include "server_SocketPassive.h"

class server_Server {
  //Al recibir una 'q' de entrada standar, el servidor debe cerrarse
  private:
    server_ServerConfiguration configuration;
    server_User user;
    server_DirectorySet directories;
    server_MapOfCommands commands;
    server_SocketPassive socketPassive;
    std::string lastCommandCode;

  public:
    explicit server_Server(const char* aService, const char* configurationFile);

    void run();

    server_Command* findCommand(const std::string& commandCode);

    ~server_Server();
};

#endif
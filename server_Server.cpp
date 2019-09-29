#include <iostream>
#include <utility>
#include "server_Server.h"
#include "server_CommandWelcome.h"
#include "server_Command.h"
#include "server_ClientProxy.h"


server_Server::server_Server(const char* aService, const char* configurationFile):
    configuration(configurationFile), user(&configuration),
    commands(&user, &directories,&configuration) {
  socketPassive.bind(aService);
  socketPassive.listen();
  lastCommandCode = "WELCOME";
}

void server_Server::run() {
  common_SocketPeer socketPeer = std::move(socketPassive.acceptClient());
  server_ClientProxy clientProxy(this, std::move(socketPeer));
  server_CommandWelcome command(&configuration);
  clientProxy.execute(&command, "");
  while (lastCommandCode != "QUIT") {
    std::string clientMessage;
    std::string commandCode;
    std::string commandArgument;
    clientProxy.receiveMessage(&clientMessage);
    clientProxy.decode(clientMessage, &commandCode, &commandArgument);
    server_Command* aCommand = findCommand(commandCode);
    clientProxy.execute(aCommand, commandArgument);
    user.lastCommandWas(commandCode);
    lastCommandCode = commandCode;
  }
}

server_Command* server_Server::findCommand(const std::string& commandCode) {
  return commands.find(commandCode);
}

server_Server::~server_Server() {
}

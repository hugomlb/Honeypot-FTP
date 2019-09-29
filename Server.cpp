#include <iostream>
#include <utility>
#include "Server.h"
#include "CommandWelcome.h"
#include "Command.h"
#include "ClientProxy.h"


Server::Server() : user(&configuration), commands(&user, &directories,
    &configuration) {
  socketPassive.bind();
  socketPassive.listen();
  lastCommandCode = "WELCOME";
}

void Server::run() {
  SocketPeer socketPeer = std::move(socketPassive.acceptClient());
  ClientProxy clientProxy(this);
  CommandWelcome command(&configuration);
  command.execute("");
  while (lastCommandCode != "QUIT") {
    clientProxy.receiveMessage(&socketPeer);
  }
}

void Server::executeCommand(const std::string& commandCode, std::string commandArgument) {
  commands.findAndExecute(commandCode, std::move(commandArgument));
  user.lastCommandWas(commandCode);
  lastCommandCode = commandCode;
}

Server::~Server() {
}

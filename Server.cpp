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
  ClientProxy clientProxy(this, std::move(socketPeer));
  CommandWelcome command(&configuration);
  clientProxy.execute(&command, "");
  while (lastCommandCode != "QUIT") {
    std::string clientMessage;
    std::string commandCode;
    std::string commandArgument;
    clientProxy.receiveMessage(&clientMessage);
    clientProxy.decode(clientMessage, &commandCode, &commandArgument);
    Command* aCommand = findCommand(commandCode);
    clientProxy.execute(aCommand, commandArgument);
    user.lastCommandWas(commandCode);
    lastCommandCode = commandCode;
  }
}

Command* Server::findCommand(const std::string& commandCode) {
  return commands.find(commandCode);
}

Server::~Server() {
}

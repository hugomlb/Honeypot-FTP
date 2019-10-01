#include <iostream>
#include "server_ClientProxy.h"
#include "common_SocketPeerException.h"

server_ClientProxy::server_ClientProxy(server_ServerConfiguration* config,
      server_MapOfCommands* mapOfCommands, common_SocketPeer socketPeer):
    user(config), comunicationProtocol(std::move(socketPeer)) {
  lastCommandCode = "";
  isTalking = true;
  commands = mapOfCommands;
}

void server_ClientProxy::run() {
  try {
    communicate();
  } catch (common_SocketPeerException &e) {
  }
  isTalking = false;
}

void server_ClientProxy::communicate() {
  while (lastCommandCode != "QUIT" && isTalking) {
    std::string clientMessage;
    std::string commandCode;
    std::string commandArgument;
    comunicationProtocol.receiveMessage(&clientMessage);
    comunicationProtocol.decode(clientMessage, &commandCode, &commandArgument);
    server_Command* aCommand = findCommand(commandCode);
    comunicationProtocol.execute(aCommand, commandArgument, &user);
    user.lastCommandWas(commandCode);
    lastCommandCode = commandCode;
  }
}

void server_ClientProxy::kill() {
  comunicationProtocol.kill();
  isTalking = false;
}

server_Command *server_ClientProxy::findCommand(std::string commandCode) {
  return commands -> find(commandCode);
}

void server_ClientProxy::welcomenClient(server_CommandWelcome *welcome) {
  comunicationProtocol.execute(welcome, "", &user);
}

bool server_ClientProxy::isDead() {
  return !(isTalking);
}

server_ClientProxy::~server_ClientProxy() {
}

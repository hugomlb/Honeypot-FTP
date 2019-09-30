#include "server_ConnectedClient.h"
#include "common_SocketPeerException.h"

server_ConnectedClient::server_ConnectedClient(server_ServerConfiguration *configuration,
    server_DirectorySet* directories, common_SocketPeer socketPeer):
    user(configuration), commands(&user, directories, configuration), clientProxy(std::move(socketPeer)){
  lastCommandCode = "";
  isTalking = false;
}

void server_ConnectedClient::run() {
  isTalking = true;
  try {
    while (lastCommandCode != "QUIT" && !isDead()) {
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
  } catch (common_SocketPeerException &e) {
  }
}

void server_ConnectedClient::kill() {
  clientProxy.kill();
  isTalking = false;
}

server_Command *server_ConnectedClient::findCommand(std::string commandCode) {
  return commands.find(commandCode);
}

void server_ConnectedClient::welcomenClient(server_CommandWelcome *welcome) {
  clientProxy.execute(welcome, "");
}

bool server_ConnectedClient::isDead() {
  return !isTalking;
}

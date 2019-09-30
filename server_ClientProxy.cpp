#include "server_ClientProxy.h"
#include "common_SocketPeerException.h"

server_ClientProxy::server_ClientProxy(server_ServerConfiguration *configuration,
    server_ProtectedDirectorySet* directories, common_SocketPeer socketPeer):
    user(configuration), commands(&user, directories, configuration), clientProxy(std::move(socketPeer)){
  lastCommandCode = "";
  isTalking = false;
}

void server_ClientProxy::run() {
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

void server_ClientProxy::kill() {
  clientProxy.kill();
  isTalking = false;
}

server_Command *server_ClientProxy::findCommand(std::string commandCode) {
  return commands.find(commandCode);
}

void server_ClientProxy::welcomenClient(server_CommandWelcome *welcome) {
  clientProxy.execute(welcome, "");
}

bool server_ClientProxy::isDead() {
  return !isTalking;
}

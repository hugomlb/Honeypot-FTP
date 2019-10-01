#include <iostream>
#include "server_Command.h"

server_Command::server_Command(server_ServerConfiguration* configuration) {
  clientNotLogged = configuration -> getValueOf("clientNotLogged");
}

void server_Command::askForLogin(common_SocketPeer* socketPeer) {
  sendMessage("530 " + clientNotLogged, socketPeer);
}

void server_Command::sendMessage(const std::string& aMessage, common_SocketPeer* socketPeer) {
  socketPeer -> send( aMessage + "\n");
}

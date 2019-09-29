#include <iostream>
#include "server_Command.h"

server_Command::server_Command(server_ServerConfiguration* configuration) {
  clientNotLogged = configuration -> getValueOf("clientNotLogged");
}

void server_Command::printMessage(const std::string& aMessage) {
  std::cout << aMessage << std::endl;
}

void server_Command::askForLogin(common_SocketPeer* socketPeer) {
  sendMessage("530 " + clientNotLogged, socketPeer);
}

void server_Command::sendMessage(std::string aMessage, common_SocketPeer* socketPeer) {
  socketPeer -> send( aMessage + "\n");
}
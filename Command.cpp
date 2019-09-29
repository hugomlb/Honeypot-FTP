#include <iostream>
#include "Command.h"

Command::Command(ServerConfiguration* configuration) {
  clientNotLogged = configuration -> getValueOf("clientNotLogged");
}

void Command::printMessage(const std::string& aMessage) {
  std::cout << aMessage << std::endl;
}

void Command::askForLogin(SocketPeer* socketPeer) {
  sendMessage("530 " + clientNotLogged, socketPeer);
}

void Command::sendMessage(std::string aMessage, SocketPeer* socketPeer) {
  socketPeer -> send( aMessage + "\n");
}

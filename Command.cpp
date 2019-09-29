#include <iostream>
#include "Command.h"

Command::Command(ServerConfiguration* configuration) {
  clientNotLogged = configuration -> getValueOf("clientNotLogged");
}

void Command::printMessage(const std::string& aMessage) {
  std::cout << aMessage << std::endl;
}

void Command::askForLogin() {
  //sendMessage("530 " + clientNotLogged);
  printMessage("530 " + clientNotLogged);
}

void Command::sendMessage(std::string aMessage, SocketPeer* socketPeer) {
  socketPeer -> send( aMessage + "\n");
}

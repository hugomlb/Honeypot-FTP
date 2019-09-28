#include <iostream>
#include "Command.h"

Command::Command(ServerConfiguration *configuration) {
  clientNotLogged = configuration -> getValueOf("clientNotLogged");
}

void Command::printMessage(const std::string& aMessage) {
  std::cout << aMessage << std::endl;
}

void Command::askForLogin() {
  printMessage("530 " + clientNotLogged);
}

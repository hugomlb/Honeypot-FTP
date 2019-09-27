#include <iostream>
#include "Command.h"

void Command::printMessage(const std::string& aMessage) {
  std::cout << aMessage << std::endl;
}

void Command::askForLoggin() {
  printMessage("530 Please login with USER and PASS.");
}

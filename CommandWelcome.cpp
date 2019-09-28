#include "CommandWelcome.h"

CommandWelcome::CommandWelcome(ServerConfiguration *configuration) {
  newClient = configuration -> getValueOf("newClient");
}

void CommandWelcome::execute(std::string argument) {
  printMessage("230 " + newClient);
}

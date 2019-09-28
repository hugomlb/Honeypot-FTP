#include "CommandQuit.h"

void CommandQuit::execute(std::string argument) {
  printMessage("221 " + quitSuccess);
}

CommandQuit::CommandQuit(ServerConfiguration *configuration) {
  quitSuccess = configuration -> getValueOf("quitSuccess");
}

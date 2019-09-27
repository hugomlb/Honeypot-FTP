#include "CommandQuit.h"

void CommandQuit::execute(std::string argument) {
  printMessage("221 Goodbye.");
}

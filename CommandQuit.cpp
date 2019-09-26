#include "CommandQuit.h"

void CommandQuit::execute() {
  printMessage("221 Goodbye.");
}

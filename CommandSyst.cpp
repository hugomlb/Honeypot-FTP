#include "CommandSyst.h"

CommandSyst::CommandSyst(User *aUser) {
  user = aUser;
}

void CommandSyst::execute(std::string argument) {
  if (user -> isLogged(this)) {
    printMessage("215 UNIX Type: L8");
  }
}

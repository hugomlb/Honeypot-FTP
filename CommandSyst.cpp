#include "CommandSyst.h"
#include "CommandInvalid.h"

CommandSyst::CommandSyst(User *aUser) {
  user = aUser;
}

void CommandSyst::execute(std::string argument) {
  if (argument.empty()) {
    systemInfo();
  } else {
    CommandInvalid commandInvalid;
    commandInvalid.execute("");
  }
}

void CommandSyst::systemInfo() {
  if (user -> isLogged(this)) {
    printMessage("215 UNIX Type: L8");
  }
}

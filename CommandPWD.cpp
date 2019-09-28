#include "CommandPWD.h"
#include "CommandInvalid.h"

void CommandPWD::execute(std::string argument) {
  if (argument.empty()) {
    currentDirectory();
  } else {
    CommandInvalid commandInvalid;
    commandInvalid.execute("");
  }
}

CommandPWD::CommandPWD(User *aUser) {
  user = aUser;
}

void CommandPWD::currentDirectory() {
  if (user -> isLogged(this)) {
    printMessage("257 '/home/admin/ftp' is the current directory.");
  }
}

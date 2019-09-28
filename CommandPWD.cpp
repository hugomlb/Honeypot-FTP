#include "CommandPWD.h"
#include "CommandInvalid.h"

CommandPWD::CommandPWD(User *aUser, ServerConfiguration* configuration):
    Command(configuration){
  user = aUser;
  currentDirectoryMsg = configuration -> getValueOf("currentDirectoryMsg");
}

void CommandPWD::execute(std::string argument) {
  if (argument.empty()) {
    currentDirectory();
  }
}

void CommandPWD::currentDirectory() {
  if (user -> isLogged(this)) {
    printMessage("257 " + currentDirectoryMsg);
  }
}

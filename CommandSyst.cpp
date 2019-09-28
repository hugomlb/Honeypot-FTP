#include "CommandSyst.h"
#include "CommandInvalid.h"
#include "ServerConfiguration.h"

CommandSyst::CommandSyst(User* aUser, ServerConfiguration* configuration) {
  user = aUser;
  systemInfo = configuration -> getValueOf("systemInfo");
}

void CommandSyst::execute(std::string argument) {
  if (argument.empty()) {
    systemInformation();
  } else {
    /*CommandInvalid commandInvalid;
    commandInvalid.execute("");*/
  }
}

void CommandSyst::systemInformation() {
  if (user -> isLogged(this)) {
    printMessage("215 " + systemInfo);
  }
}

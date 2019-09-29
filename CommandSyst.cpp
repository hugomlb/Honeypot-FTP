#include "CommandSyst.h"
#include "CommandInvalid.h"
#include "ServerConfiguration.h"

CommandSyst::CommandSyst(User* aUser, ServerConfiguration* configuration):
    Command(configuration){
  user = aUser;
  systemInfo = configuration -> getValueOf("systemInfo");
}

void CommandSyst::execute(std::string argument, SocketPeer* socketPeer) {
  if (argument.empty()) {
    systemInformation();
  }
}

void CommandSyst::systemInformation() {
  if (user -> isLogged(this)) {
    printMessage("215 " + systemInfo);
  }
}

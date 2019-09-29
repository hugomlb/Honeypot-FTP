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
    systemInformation(socketPeer);
  }
}

void CommandSyst::systemInformation(SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    sendMessage("215 " + systemInfo, socketPeer);
  }
}

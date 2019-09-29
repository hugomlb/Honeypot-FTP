#include "server_CommandSyst.h"
#include "server_CommandInvalid.h"
#include "server_ServerConfiguration.h"

server_CommandSyst::server_CommandSyst(server_User* aUser, server_ServerConfiguration* configuration):
    server_Command(configuration){
  user = aUser;
  systemInfo = configuration -> getValueOf("systemInfo");
}

void server_CommandSyst::execute(std::string argument, common_SocketPeer* socketPeer) {
  if (argument.empty()) {
    systemInformation(socketPeer);
  }
}

void server_CommandSyst::systemInformation(common_SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    sendMessage("215 " + systemInfo, socketPeer);
  }
}

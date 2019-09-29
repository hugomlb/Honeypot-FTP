#include "server_CommandPWD.h"
#include "server_CommandInvalid.h"
#include "common_SocketPeer.h"

server_CommandPWD::server_CommandPWD(server_User *aUser, server_ServerConfiguration* configuration):
    server_Command(configuration){
  user = aUser;
  currentDirectoryMsg = configuration -> getValueOf("currentDirectoryMsg");
}

void server_CommandPWD::execute(std::string argument, common_SocketPeer* socketPeer) {
  if (argument.empty()) {
    currentDirectory(socketPeer);
  }
}

void server_CommandPWD::currentDirectory(common_SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    sendMessage("257 " + currentDirectoryMsg, socketPeer);
  }
}

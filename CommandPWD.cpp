#include "CommandPWD.h"
#include "CommandInvalid.h"
#include "SocketPeer.h"

CommandPWD::CommandPWD(User *aUser, ServerConfiguration* configuration):
    Command(configuration){
  user = aUser;
  currentDirectoryMsg = configuration -> getValueOf("currentDirectoryMsg");
}

void CommandPWD::execute(std::string argument, SocketPeer* socketPeer) {
  if (argument.empty()) {
    currentDirectory(socketPeer);
  }
}

void CommandPWD::currentDirectory(SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    sendMessage("257 " + currentDirectoryMsg, socketPeer);
  }
}

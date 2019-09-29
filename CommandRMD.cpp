#include "CommandRMD.h"
#include "DirectorySetException.h"
#include "CommandInvalid.h"
#include "SocketPeer.h"

CommandRMD::CommandRMD(DirectorySet* directorySet, User* aUser,
    ServerConfiguration* configuration): Command(configuration) {
  directories = directorySet;
  user = aUser;
  rmdSuccess = configuration -> getValueOf("rmdSuccess");
  rmdFailed = configuration -> getValueOf("rmdFailed");
}

void CommandRMD::execute(std::string argument, SocketPeer* socketPeer) {
  if(!argument.empty()) {
    removeDirectory(argument, socketPeer);
  }
}

void CommandRMD::removeDirectory(const std::string& aDirectoryName, SocketPeer* socketPeer) {
  if(user -> isLogged(this, socketPeer)) {
    try {
      directories -> removeDirectory(aDirectoryName);
      sendMessage("250 " + rmdSuccess, socketPeer);
    } catch (DirectorySetException &e) {
      sendMessage("550 " + rmdFailed, socketPeer);
    }
  }
}


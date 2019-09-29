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
    removeDirectory(argument);
  }
}

void CommandRMD::removeDirectory(const std::string& aDirectoryName) {
  if(user -> isLogged(this)) {
    try {
      directories -> removeDirectory(aDirectoryName);
      printMessage("250 " + rmdSuccess);
    } catch (DirectorySetException &e) {
      printMessage("550 " + rmdFailed);
    }
  }
}


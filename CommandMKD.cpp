#include "CommandMKD.h"
#include "DirectorySetException.h"
#include "CommandInvalid.h"
#include "SocketPeer.h"

CommandMKD::CommandMKD(DirectorySet* directorySet, User* aUser,
    ServerConfiguration* configuration): Command(configuration) {
  directories = directorySet;
  user = aUser;
  mkdSuccess = configuration -> getValueOf("mkdSuccess");
  mkdFailed = configuration -> getValueOf("mkdFailed");
}

void CommandMKD::execute(std::string argument, SocketPeer* socketPeer) {
  if (!argument.empty()) {
    makeDirectory(argument);
  }
}

void CommandMKD::makeDirectory(const std::string& aDirectoryName) {
  if (user -> isLogged(this)) {
    try {
      directories -> addDirectory(aDirectoryName);
      printMessage("257 " + aDirectoryName + " " + mkdSuccess);
    } catch (DirectorySetException &e) {
      printMessage("550 " + mkdFailed);
    }
  }
}

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
    makeDirectory(argument, socketPeer);
  }
}

void CommandMKD::makeDirectory(const std::string& aDirectoryName, SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    try {
      directories -> addDirectory(aDirectoryName);
      sendMessage("257 " + aDirectoryName + " " + mkdSuccess, socketPeer);
    } catch (DirectorySetException &e) {
      sendMessage("550 " + mkdFailed, socketPeer);
    }
  }
}

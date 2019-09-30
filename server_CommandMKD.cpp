#include "server_CommandMKD.h"
#include "server_DirectorySetException.h"
#include "server_CommandInvalid.h"
#include "common_SocketPeer.h"

server_CommandMKD::server_CommandMKD(server_DirectorySet* directorySet, server_User* aUser,
                                     server_ServerConfiguration* configuration): server_Command(configuration) {
  directories = directorySet;
  user = aUser;
  mkdSuccess = configuration -> getValueOf("mkdSuccess");
  mkdFailed = configuration -> getValueOf("mkdFailed");
}

void server_CommandMKD::execute(std::string argument, common_SocketPeer* socketPeer) {
  if (!argument.empty()) {
    makeDirectory(argument, socketPeer);
  }
}

void server_CommandMKD::makeDirectory(const std::string& aDirectoryName, common_SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    try {
      directories -> addDirectory(aDirectoryName);
      std::string commandCode = "257 ";
      sendMessage(commandCode + '"' + aDirectoryName + '"' + " " + mkdSuccess, socketPeer);
    } catch (server_DirectorySetException &e) {
      sendMessage("550 " + mkdFailed, socketPeer);
    }
  }
}

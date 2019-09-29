#include "server_CommandRMD.h"
#include "server_DirectorySetException.h"
#include "server_CommandInvalid.h"
#include "common_SocketPeer.h"

server_CommandRMD::server_CommandRMD(server_DirectorySet* directorySet, server_User* aUser,
                                     server_ServerConfiguration* configuration): server_Command(configuration) {
  directories = directorySet;
  user = aUser;
  rmdSuccess = configuration -> getValueOf("rmdSuccess");
  rmdFailed = configuration -> getValueOf("rmdFailed");
}

void server_CommandRMD::execute(std::string argument, common_SocketPeer* socketPeer) {
  if(!argument.empty()) {
    removeDirectory(argument, socketPeer);
  }
}

void server_CommandRMD::removeDirectory(const std::string& aDirectoryName, common_SocketPeer* socketPeer) {
  if(user -> isLogged(this, socketPeer)) {
    try {
      directories -> removeDirectory(aDirectoryName);
      sendMessage("250 " + rmdSuccess, socketPeer);
    } catch (server_DirectorySetException &e) {
      sendMessage("550 " + rmdFailed, socketPeer);
    }
  }
}

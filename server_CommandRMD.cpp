#include "server_CommandRMD.h"
#include "server_ProtectedDirectorySetException.h"
#include "server_CommandInvalid.h"
#include "common_SocketPeer.h"

server_CommandRMD::server_CommandRMD(server_ProtectedDirectorySet* directorySet,
    server_ServerConfiguration* configuration): server_Command(configuration) {
  directories = directorySet;
  rmdSuccess = configuration -> getValueOf("rmdSuccess");
  rmdFailed = configuration -> getValueOf("rmdFailed");
}

void server_CommandRMD::execute(std::string argument, server_User *user,
                                common_SocketPeer *socketPeer) {
  if(user -> isLogged()) {
    try {
      directories -> removeDirectory(argument);
      std::string commandCode = "250 ";
      sendMessage(commandCode + '"' + argument + '"' + " " + rmdSuccess,
          socketPeer);
    } catch (server_ProtectedDirectorySetException &e) {
      sendMessage("550 " + rmdFailed, socketPeer);
    }
  } else {
    askForLogin(socketPeer);
  }
}

#include "server_CommandMKD.h"
#include "server_ProtectedDirectorySetException.h"
#include "server_CommandInvalid.h"
#include "common_SocketPeer.h"

server_CommandMKD::server_CommandMKD(server_ProtectedDirectorySet* directorySet,
    server_ServerConfiguration* configuration): server_Command(configuration) {
  directories = directorySet;
  mkdSuccess = configuration -> getValueOf("mkdSuccess");
  mkdFailed = configuration -> getValueOf("mkdFailed");
}

void server_CommandMKD::execute(std::string argument, server_User *user,
                                common_SocketPeer *socketPeer) {
  if (user -> isLogged()) {
    try {
      directories -> addDirectory(argument);
      std::string commandCode = "257 ";
      sendMessage(commandCode + '"' + argument + '"' + " " +
      mkdSuccess, socketPeer);
    } catch (server_ProtectedDirectorySetException &e) {
      sendMessage("550 " + mkdFailed, socketPeer);
    }
  } else {
    askForLogin(socketPeer);
  }
}

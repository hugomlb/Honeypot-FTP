#include "server_CommandSyst.h"
#include "server_ServerConfiguration.h"

server_CommandSyst::server_CommandSyst(server_ServerConfiguration* configuration):
    server_Command(configuration){
  systemInfo = configuration -> getValueOf("systemInfo");
}

void server_CommandSyst::execute(std::string argument, server_User *user,
                                 common_SocketPeer *socketPeer) {
  if (user -> isLogged()) {
    sendMessage("215 " + systemInfo, socketPeer);
  } else {
    askForLogin(socketPeer);
  }
}

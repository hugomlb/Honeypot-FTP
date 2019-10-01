#include "server_CommandPWD.h"
#include "common_SocketPeer.h"

server_CommandPWD::server_CommandPWD(server_ServerConfiguration* configuration):
    server_Command(configuration){
  currentDirectoryMsg = configuration -> getValueOf("currentDirectoryMsg");
}

void server_CommandPWD::execute(std::string argument, server_User *user,
                                common_SocketPeer *socketPeer) {
  if (user -> isLogged()) {
    sendMessage("257 " + currentDirectoryMsg, socketPeer);
  } else {
    askForLogin(socketPeer);
  }
}

server_CommandPWD::~server_CommandPWD() {
}

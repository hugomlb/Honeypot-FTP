#include "server_CommandInvalid.h"
#include "common_SocketPeer.h"

server_CommandInvalid::server_CommandInvalid(server_ServerConfiguration *configuration):
    server_Command(configuration) {
  unknownCommand = configuration -> getValueOf("unknownCommand");
}

void server_CommandInvalid::execute(std::string argument, server_User* user,
                                    common_SocketPeer* socketPeer) {
  sendMessage("530 " + unknownCommand, socketPeer);
}

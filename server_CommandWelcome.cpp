#include "server_CommandWelcome.h"
#include "common_SocketPeer.h"

server_CommandWelcome::server_CommandWelcome(server_ServerConfiguration *configuration):
    server_Command(configuration) {
  newClient = configuration -> getValueOf("newClient");
}

void server_CommandWelcome::execute(std::string argument, common_SocketPeer* socketPeer) {
  sendMessage("230 " + newClient, socketPeer);
}

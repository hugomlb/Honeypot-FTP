#include "server_CommandWelcome.h"
#include "common_SocketPeer.h"

server_CommandWelcome::server_CommandWelcome(server_ServerConfiguration*
    configuration): server_Command(configuration) {
  newClient = configuration -> getValueOf("newClient");
}

void server_CommandWelcome::execute(std::string argument, server_User* user,
                                    common_SocketPeer* socketPeer) {
  sendMessage("220 " + newClient, socketPeer);
}

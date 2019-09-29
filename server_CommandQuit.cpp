#include "server_CommandQuit.h"
#include "common_SocketPeer.h"

server_CommandQuit::server_CommandQuit(server_ServerConfiguration *configuration):
    server_Command(configuration) {
  quitSuccess = configuration -> getValueOf("quitSuccess");
}

void server_CommandQuit::execute(std::string argument, common_SocketPeer* socketPeer) {
  sendMessage("221 " + quitSuccess, socketPeer);
}

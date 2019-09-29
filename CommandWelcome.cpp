#include "CommandWelcome.h"
#include "SocketPeer.h"

CommandWelcome::CommandWelcome(ServerConfiguration *configuration):
    Command(configuration) {
  newClient = configuration -> getValueOf("newClient");
}

void CommandWelcome::execute(std::string argument, SocketPeer* socketPeer) {
  sendMessage("230 " + newClient, socketPeer);
}

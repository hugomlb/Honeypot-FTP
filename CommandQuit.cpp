#include "CommandQuit.h"
#include "SocketPeer.h"

CommandQuit::CommandQuit(ServerConfiguration *configuration):
    Command(configuration) {
  quitSuccess = configuration -> getValueOf("quitSuccess");
}

void CommandQuit::execute(std::string argument, SocketPeer* socketPeer) {
  sendMessage("221 " + quitSuccess, socketPeer);
}

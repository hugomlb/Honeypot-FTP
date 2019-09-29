#include "CommandQuit.h"
#include "SocketPeer.h"

void CommandQuit::execute(std::string argument, SocketPeer* socketPeer) {
  printMessage("221 " + quitSuccess);
}

CommandQuit::CommandQuit(ServerConfiguration *configuration):
    Command(configuration) {
  quitSuccess = configuration -> getValueOf("quitSuccess");
}

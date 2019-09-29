#include "CommandHelp.h"
#include "SocketPeer.h"


CommandHelp::CommandHelp(ServerConfiguration* configuration):
    Command(configuration) {
  commands = configuration -> getValueOf("commands");

}

void CommandHelp::execute(std::string argument, SocketPeer* socketPeer) {
  sendMessage("214 " + commands, socketPeer);
}

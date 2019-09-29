#include <sstream>
#include "ClientProxy.h"

ClientProxy::ClientProxy(Server *server) {
  this -> server = server;
}

void ClientProxy::receiveMessage(SocketPeer* socketPeer) {
  std::string commandCode;
  std::string commandArgument;
  std::string aCommand;
  socketPeer -> receive(&aCommand);
  if (aCommand.find_first_of(' ') != std::string::npos) {
    std::istringstream test(aCommand);
    getline(test, commandCode, ' ');
    getline(test, commandArgument);
  } else {
    std::istringstream test(aCommand);
    getline(test, commandCode);
  }
  server -> executeCommand(commandCode, commandArgument);
}

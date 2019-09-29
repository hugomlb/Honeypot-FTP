#include <iostream>
#include "ServerProxy.h"

ServerProxy::ServerProxy() {
  socketActive.connect();
}

void ServerProxy::executeCommand(std::string aCommand) {
  std::string commandToSend;
  for (char& it : aCommand) {
    commandToSend += it;
  }
  commandToSend += '\n';
  socketActive.send(commandToSend);
}

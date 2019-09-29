#include <iostream>
#include "ServerProxy.h"

ServerProxy::ServerProxy() {
  socketActive.connect();
  std::string answer;
  socketActive.receive(&answer);
  std::cout << answer;
}

void ServerProxy::executeCommand(std::string aCommand) {
  std::string commandToSend;
  for (char& it : aCommand) {
    commandToSend += it;
  }
  commandToSend += '\n';
  socketActive.send(commandToSend);
  std::string answer;
  socketActive.receive(&answer);
  std::cout << answer;
}

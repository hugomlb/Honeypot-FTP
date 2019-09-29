#include <iostream>
#include <sstream>
#include "client_ServerProxy.h"

client_ServerProxy::client_ServerProxy(const char* hostName, const char* service) {
  socketActive.connect(hostName, service);
  std::string answer;
  socketActive.receive(&answer);
  std::cout << answer;
}

void client_ServerProxy::executeCommand(std::string aCommand) {
  std::string commandToSend;
  std::string answer;
  std::string commandCode;
  for (char& it : aCommand) {
    commandToSend += it;
  }
  commandToSend += '\n';
  socketActive.send(commandToSend);
  answer = getAnswer();
  std::istringstream test(answer);
  std::cout << answer;
  getline(test, commandCode, ' ');
  if (commandCode == "150") {
    while (commandCode != "226") {
      answer = getAnswer();
      std::cout << answer;
      std::istringstream test2(answer);
      getline(test2, commandCode, ' ');
    }
  }
}

std::string client_ServerProxy::getAnswer() {
  std::string answer;
  socketActive.receive(&answer);
  return answer;
}

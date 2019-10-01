#include <iostream>
#include <sstream>
#include "client_ClientCommunicationProtocol.h"

client_ClientCommunicationProtocol::client_ClientCommunicationProtocol(
    const char *hostName, const char *service) {
  socketActive.connect(hostName, service);
}

void client_ClientCommunicationProtocol::receiveMessage() {
  std::string answer = getAnswer();
  std::string commandCode;
  std::istringstream command(answer);
  getline(command, commandCode, ' ');
  if (commandCode == "150") {
    while (commandCode != "226") {
      answer = getAnswer();
      std::istringstream command2(answer);
      getline(command2, commandCode, ' ');
    }
  }
}

std::string client_ClientCommunicationProtocol::getAnswer() {
  std::string answer;
  socketActive.receive(&answer);
  std::cout << answer;
  return answer;
}

void client_ClientCommunicationProtocol::sendMessage(std::string aCommand) {
  aCommand += '\n';
  socketActive.send(aCommand);
}

client_ClientCommunicationProtocol::~client_ClientCommunicationProtocol() {
}

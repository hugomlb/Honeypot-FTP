#include <sstream>
#include "ClientProxy.h"

ClientProxy::ClientProxy(Server *server, SocketPeer aSocketPeer): socketPeer(std::move(aSocketPeer)) {
  this -> server = server;
}

void ClientProxy::receiveMessage(std::string* received) {
  socketPeer.receive(received);
}

void ClientProxy::decode(std::string aCommand,std::string *commandCode, std::string* argument) {
  if (aCommand.find_first_of(' ') != std::string::npos) {
    std::istringstream test(aCommand);
    getline(test, *commandCode, ' ');
    getline(test, *argument);
  } else {
    std::istringstream test(aCommand);
    getline(test, *commandCode);
  }
}

void ClientProxy::execute(Command *command, std::string argument) {
  command -> execute(std::move(argument), &socketPeer);
}

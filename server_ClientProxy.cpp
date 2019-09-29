#include <sstream>
#include "server_ClientProxy.h"

server_ClientProxy::server_ClientProxy(common_SocketPeer aSocketPeer): socketPeer(std::move(aSocketPeer)) {
}

void server_ClientProxy::receiveMessage(std::string* received) {
  socketPeer.receive(received);
}

void server_ClientProxy::decode(std::string aCommand, std::string *commandCode, std::string* argument) {
  if (aCommand.find_first_of(' ') != std::string::npos) {
    std::istringstream test(aCommand);
    getline(test, *commandCode, ' ');
    getline(test, *argument);
  } else {
    std::istringstream test(aCommand);
    getline(test, *commandCode);
  }
}

void server_ClientProxy::execute(server_Command *command, std::string argument) {
  command -> execute(std::move(argument), &socketPeer);
}

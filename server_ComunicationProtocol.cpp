#include <sstream>
#include "server_ComunicationProtocol.h"

server_ComunicationProtocol::server_ComunicationProtocol(common_SocketPeer aSocketPeer): socketPeer(std::move(aSocketPeer)) {
}

void server_ComunicationProtocol::receiveMessage(std::string* received) {
  socketPeer.receive(received);
}

void server_ComunicationProtocol::decode(std::string aCommand, std::string* commandCode, std::string* argument) {
  if (aCommand.find_first_of(' ') != std::string::npos) {
    std::istringstream test(aCommand);
    getline(test, *commandCode, ' ');
    getline(test, *argument);
  } else {
    std::istringstream test(aCommand);
    getline(test, *commandCode);
  }
}

void server_ComunicationProtocol::execute(server_Command* command, std::string argument, server_User* user) {
  command -> execute(std::move(argument), user, &socketPeer);
}

void server_ComunicationProtocol::kill() {
  socketPeer.close();
}

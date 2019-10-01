#include <sstream>
#include "server_ServerComunicationProtocol.h"

server_ServerComunicationProtocol::server_ServerComunicationProtocol(common_SocketPeer
    aSocketPeer): socketPeer(std::move(aSocketPeer)) {
}

void server_ServerComunicationProtocol::receiveMessage(std::string* received) {
  socketPeer.receive(received);
}

void server_ServerComunicationProtocol::decode(std::string aCommand, std::string*
                                      commandCode, std::string* argument) {
  std::istringstream userCommand(aCommand);
  if (aCommand.find_first_of(' ') != std::string::npos) {
    getline(userCommand, *commandCode, ' ');
    getline(userCommand, *argument);
  } else {
    getline(userCommand, *commandCode);
  }
}

void server_ServerComunicationProtocol::execute(server_Command* command, std::string
                                           argument, server_User* user) {
  command -> execute(std::move(argument), user, &socketPeer);
}

void server_ServerComunicationProtocol::kill() {
  socketPeer.close();
}

server_ServerComunicationProtocol::~server_ServerComunicationProtocol() {
}

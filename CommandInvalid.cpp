#include "CommandInvalid.h"
#include "SocketPeer.h"

CommandInvalid::CommandInvalid(ServerConfiguration *configuration):
    Command(configuration) {
  unknownCommand = configuration -> getValueOf("unknownCommand");
}

void CommandInvalid::execute(std::string argument, SocketPeer* socketPeer) {
  sendMessage("500 " + unknownCommand, socketPeer);
}

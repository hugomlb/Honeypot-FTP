#include "CommandInvalid.h"

CommandInvalid::CommandInvalid(ServerConfiguration *configuration):
    Command(configuration) {
  unknownCommand = configuration -> getValueOf("unknownCommand");
}

void CommandInvalid::execute(std::string argument) {
  printMessage("500 " + unknownCommand);
}

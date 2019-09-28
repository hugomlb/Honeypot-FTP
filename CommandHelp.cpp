#include "CommandHelp.h"


CommandHelp::CommandHelp(ServerConfiguration* configuration):
    Command(configuration) {
  commands = configuration -> getValueOf("commands");

}

void CommandHelp::execute(std::string argument) {
  printMessage("214 " + commands);
}

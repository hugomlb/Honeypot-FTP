#include <sstream>
#include "ClientProxy.h"

void ClientProxy::send(const std::string& aCommand) {
  std::istringstream command(aCommand);
  std::string commandToExecute;
  getline(command, commandToExecute);
  server.executeCommand(commandToExecute);
}

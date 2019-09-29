#include "CommandUser.h"

CommandUser::CommandUser(User* aUser, ServerConfiguration* configuration):
    Command(configuration){
  user = aUser;
  passRequired = configuration -> getValueOf("passRequired");
}

void CommandUser::execute(std::string argument, SocketPeer* socketPeer) {
  user -> enterUserName(argument);
  printMessage("331 " + passRequired);
}

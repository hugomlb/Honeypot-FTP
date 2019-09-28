#include "CommandUser.h"

CommandUser::CommandUser(User* aUser, ServerConfiguration* configuration) {
  user = aUser;
  passRequired = configuration -> getValueOf("passRequired");
}

void CommandUser::execute(std::string argument) {
  user -> enterUserName(argument);
  printMessage("331 " + passRequired);
}

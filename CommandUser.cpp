#include "CommandUser.h"

CommandUser::CommandUser(User *aUser) {
  user = aUser;
}

void CommandUser::execute(std::string argument) {
  user -> enterUserName(argument);
  printMessage("331 Please specify the password.");
}

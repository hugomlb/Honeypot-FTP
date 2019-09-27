#include "CommandPWD.h"

void CommandPWD::execute(std::string argument) {
  if (user -> isLogged(this)) {
    printMessage("257 '/home/admin/ftp' is the current directory.");
  }
}

CommandPWD::CommandPWD(User *aUser) {
  user = aUser;
}

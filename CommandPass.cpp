#include "CommandPass.h"

#define LOGGED 0
#define NOT_LOGGED -1

CommandPass::CommandPass(User *aUser) {
  user = aUser;
}

void CommandPass::execute(std::string argument) {
  int logState = user -> enterPassword(argument);
  logSuccess(logState);
}

void CommandPass::logSuccess(int logState) {
  if (logState == LOGGED) {
    printMessage("230 Login successful.");
  } else {
    printMessage("530 Login incorrect.");
  }
}

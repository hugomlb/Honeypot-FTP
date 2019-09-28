#include "CommandPass.h"

#define LOGGED 0
#define NOT_LOGGED -1

CommandPass::CommandPass(User *aUser, ServerConfiguration* configuration) {
  user = aUser;
  loginSuccess = configuration -> getValueOf("loginSuccess");
  loginFailed = configuration -> getValueOf("loginFailed");
}

void CommandPass::execute(std::string argument) {
  int logState = user -> enterPassword(argument);
  logSuccess(logState);
}

void CommandPass::logSuccess(int logState) {
  if (logState == LOGGED) {
    printMessage("230 " + loginSuccess);
  } else {
    printMessage("530 " + loginFailed);
  }
}

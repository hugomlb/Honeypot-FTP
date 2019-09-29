#include "CommandPass.h"
#include "SocketPeer.h"

#define LOGGED 0
#define NOT_LOGGED -1

CommandPass::CommandPass(User *aUser, ServerConfiguration* configuration):
    Command(configuration){
  user = aUser;
  loginSuccess = configuration -> getValueOf("loginSuccess");
  loginFailed = configuration -> getValueOf("loginFailed");
}

void CommandPass::execute(std::string argument, SocketPeer* socketPeer) {
  int logState = user -> enterPassword(argument);
  sendLogState(logState, socketPeer);
}

void CommandPass::sendLogState(int logState, SocketPeer *socketPeer) {
  if (logState == LOGGED) {
    sendMessage("230 " + loginSuccess, socketPeer);
  } else {
    sendMessage("530 " + loginFailed, socketPeer);
  }
}

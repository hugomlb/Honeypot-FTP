#include "server_CommandPass.h"
#include "common_SocketPeer.h"

#define LOGGED 0
#define NOT_LOGGED -1

server_CommandPass::server_CommandPass(server_User *aUser, server_ServerConfiguration* configuration):
    server_Command(configuration){
  user = aUser;
  loginSuccess = configuration -> getValueOf("loginSuccess");
  loginFailed = configuration -> getValueOf("loginFailed");
}

void server_CommandPass::execute(std::string argument, common_SocketPeer* socketPeer) {
  int logState = user -> enterPassword(argument);
  sendLogState(logState, socketPeer);
}

void server_CommandPass::sendLogState(int logState, common_SocketPeer *socketPeer) {
  if (logState == LOGGED) {
    sendMessage("230 " + loginSuccess, socketPeer);
  } else {
    sendMessage("530 " + loginFailed, socketPeer);
  }
}

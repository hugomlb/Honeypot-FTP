#include "client_Client.h"
#include "common_SocketPeerException.h"
#include <iostream>

client_Client::client_Client(const char* hostName, const char* service):
  serverProxy(hostName, service) {
}

void client_Client::run() {
  try {
    communicate();
  } catch (common_SocketPeerException &e){
  }
}

void client_Client::communicate() {
  std::string command;
  while (command != "QUIT" ) {
    getline(std::cin, command);
    if (!std::cin.eof()){
      serverProxy.executeCommand(command);
    } else {
      command = "QUIT";
    }
  }
}

client_Client::~client_Client() {
}

#include "client_Client.h"
#include "client_ServerProxy.h"
#include "common_SocketPeerException.h"
#include <iostream>

client_Client::client_Client() {
}

void client_Client::run(const char* hostName, const char* service) {
  client_ServerProxy server(hostName, service);
  std::string command = " ";
  try {
    while (command != "QUIT" ) {
      getline(std::cin, command);
      if (!std::cin.eof()){
        server.executeCommand(command);
      } else {
        command = "QUIT";
      }
    }
  } catch (common_SocketPeerException &e){
  }
}

client_Client::~client_Client() {
}

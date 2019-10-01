#include <iostream>
#include <utility>
#include "client_ServerProxy.h"

client_ServerProxy::client_ServerProxy(const char* hostName, const char* service)
    : communicationProtocol(hostName, service){
  communicationProtocol.receiveMessage();
}

void client_ServerProxy::executeCommand(std::string aCommand) {
  communicationProtocol.sendMessage(std::move(aCommand));
  communicationProtocol.receiveMessage();
}

client_ServerProxy::~client_ServerProxy() {
}

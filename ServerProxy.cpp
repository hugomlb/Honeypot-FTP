#include <iostream>
#include "ServerProxy.h"

void ServerProxy::executeCommand(std::string aCommand) {
  std::string commandToSend;
  for (char& it : aCommand) {
    commandToSend += it;
  }
  commandToSend += '\n';
  clientProxy.send(commandToSend);
}
//AGREGAR \n AL FINAL ANTES DE MANDAR
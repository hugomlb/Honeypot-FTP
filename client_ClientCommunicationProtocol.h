#ifndef _CLIENT_COMMUNICATION_PROTOCOL_H_
#define _CLIENT_COMMUNICATION_PROTOCOL_H_

#include "client_SocketActive.h"

class client_ClientCommunicationProtocol {
  private:
    client_SocketActive socketActive;

    std::string getAnswer();

  public:
    client_ClientCommunicationProtocol(const char* hostName, const char* service);

    void receiveMessage();

    void sendMessage(std::string aCommand);

    ~client_ClientCommunicationProtocol();
};


#endif
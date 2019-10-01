#ifndef _CLIENT_PROXY_H_
#define _CLIENT_PROXY_H_

#include "common_SocketPeer.h"
#include "server_Command.h"
#include <string>

class server_ServerComunicationProtocol {
  private:
    common_SocketPeer socketPeer;

  public:
    explicit server_ServerComunicationProtocol(common_SocketPeer aSocketPeer);

    void receiveMessage(std::string* received);

    void decode(std::string command, std::string* comandCode,
        std::string* argument);

    void execute(server_Command* command, std::string argument,
        server_User* user);

    void kill();

    ~server_ServerComunicationProtocol();
};


#endif

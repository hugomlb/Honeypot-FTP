#include "server_CommandUser.h"

server_CommandUser::server_CommandUser(server_User* aUser, server_ServerConfiguration* configuration):
    server_Command(configuration){
  user = aUser;
  passRequired = configuration -> getValueOf("passRequired");
}

void server_CommandUser::execute(std::string argument, common_SocketPeer* socketPeer) {
  user -> enterUserName(argument);
  sendMessage("331 " + passRequired, socketPeer);
}

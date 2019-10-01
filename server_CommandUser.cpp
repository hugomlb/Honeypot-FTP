#include "server_CommandUser.h"

server_CommandUser::server_CommandUser(server_ServerConfiguration* configuration):
    server_Command(configuration){
  passRequired = configuration -> getValueOf("passRequired");
}

void server_CommandUser::execute(std::string argument, server_User *user,
                                 common_SocketPeer *socketPeer) {
  user -> enterUserName(argument);
  sendMessage("331 " + passRequired, socketPeer);
}

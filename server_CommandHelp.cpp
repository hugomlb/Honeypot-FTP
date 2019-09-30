#include "server_CommandHelp.h"
#include "common_SocketPeer.h"


server_CommandHelp::server_CommandHelp(server_User* aUser,
    server_ServerConfiguration* configuration): server_Command(configuration) {
  commands = configuration -> getValueOf("commands");
  user = aUser;
}

void server_CommandHelp::execute(std::string argument, common_SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    sendMessage("214 " + commands, socketPeer);
  }
}

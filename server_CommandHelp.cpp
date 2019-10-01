#include "server_CommandHelp.h"
#include "common_SocketPeer.h"


server_CommandHelp::server_CommandHelp(server_ServerConfiguration*
    configuration): server_Command(configuration) {
  commands = configuration -> getValueOf("commands");
}

void server_CommandHelp::execute(std::string argument, server_User* user,
                                 common_SocketPeer* socketPeer) {
  if (user -> isLogged()) {
    sendMessage("214 " + commands, socketPeer);
  } else {
    askForLogin(socketPeer);
  }
}

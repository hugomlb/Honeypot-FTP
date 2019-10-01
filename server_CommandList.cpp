#include "server_CommandList.h"
#include "server_CommandInvalid.h"

server_CommandList::server_CommandList(server_ProtectedDirectorySet*
    directorySet, server_ServerConfiguration* configuration):
    server_Command(configuration) {
  directories = directorySet;
  listBegin = configuration -> getValueOf("listBegin");
  listEnd = configuration -> getValueOf("listEnd");
}

void server_CommandList::execute(std::string argument, server_User *user,
                                 common_SocketPeer *socketPeer) {
  if (user -> isLogged()) {
    sendMessage("150 " + listBegin, socketPeer);
    std::list<std::string> directoryList = directories -> getDirectoryList();
    std::list<std::string>::iterator iterator;
    for (iterator = directoryList.begin(); iterator != directoryList.end();
        iterator++) {
      sendMessage("drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 " +
      *iterator, socketPeer);
    }
    sendMessage("226 " + listEnd, socketPeer);
  } else {
    askForLogin(socketPeer);
  }
}

server_CommandList::~server_CommandList() {
}

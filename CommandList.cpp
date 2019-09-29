#include "CommandList.h"
#include "CommandInvalid.h"

CommandList::CommandList(DirectorySet *directorySet, User* aUser,
    ServerConfiguration* configuration): Command(configuration) {
  directories = directorySet;
  user = aUser;
  listBegin = configuration -> getValueOf("listBegin");
  listEnd = configuration -> getValueOf("listEnd");
}

void CommandList::execute(std::string argument, SocketPeer* socketPeer) {
  if (argument.empty()) {
    list(socketPeer);
  }
}

void CommandList::list(SocketPeer* socketPeer) {
  if (user -> isLogged(this, socketPeer)) {
    sendMessage("150 " + listBegin, socketPeer);
    std::list<std::string> directoryList = directories -> getDirectoryList();
    std::list<std::string>::iterator iterator;
    for (iterator = directoryList.begin(); iterator != directoryList.end(); iterator++) {
      printMessage("drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 " + *iterator);
    }
    printMessage("226 " + listEnd);
  }
}

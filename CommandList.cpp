#include "CommandList.h"

CommandList::CommandList(DirectorySet *directorySet) {
  this -> directories = directorySet;
}

void CommandList::execute() {
  printMessage("150 Here comes the directory listing.");
  std::list<std::string> directoryList = directories -> getDirectoryList();
  std::list<std::string>::iterator iterator;
  for (iterator = directoryList.begin(); iterator != directoryList.end(); iterator++) {
    printMessage("drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 " + *iterator);
  }
  printMessage("226 Directory send OK.");
}

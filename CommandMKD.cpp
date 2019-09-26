#include "CommandMKD.h"
#include "DirectorySetException.h"
#include <utility>

CommandMKD::CommandMKD(std::string aDirectoryName, DirectorySet* directorySet) {
  directoryName = std::move(aDirectoryName);
  directories = directorySet;
}

void CommandMKD::execute() {
  try {
    directories -> addDirectory(directoryName);
    printMessage("257 " + directoryName + " created");
  } catch (DirectorySetException &e) {
    printMessage("550 Create directory operation failed.");
  }
}

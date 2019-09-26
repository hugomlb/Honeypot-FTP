#include "CommandRMD.h"

#include <utility>
#include "DirectorySetException.h"

CommandRMD::CommandRMD(std::string aDirectoryName, DirectorySet *directorySet) {
  directoryName = std::move(aDirectoryName);
  directories = directorySet;
}
void CommandRMD::execute() {
  try {
    directories -> removeDirectory(directoryName);
    printMessage("250 Remove directory operation successful.");
  } catch (DirectorySetException &e) {
    printMessage("550 Remove directory operation failed.");
  }
}

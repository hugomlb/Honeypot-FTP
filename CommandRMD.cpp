#include "CommandRMD.h"
#include "DirectorySetException.h"

CommandRMD::CommandRMD(DirectorySet *directorySet) {
  directories = directorySet;
}

void CommandRMD::execute(std::string argument) {
  if(!argument.empty()) {
    directoryName = argument;
    execute();
  }
}

void CommandRMD::execute() {
  try {
    directories -> removeDirectory(directoryName);
    printMessage("250 Remove directory operation successful.");
  } catch (DirectorySetException &e) {
    printMessage("550 Remove directory operation failed.");
  }
}

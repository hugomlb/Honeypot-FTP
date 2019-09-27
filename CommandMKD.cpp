#include "CommandMKD.h"
#include "DirectorySetException.h"

CommandMKD::CommandMKD(DirectorySet* directorySet) {
  directories = directorySet;
}

void CommandMKD::execute(std::string argument) {
  if (!argument.empty()) {
    directoryName = argument;
    execute();
  }
}

void CommandMKD::execute() {
  try {
    directories -> addDirectory(directoryName);
    printMessage("257 " + directoryName + " created");
  } catch (DirectorySetException &e) {
    printMessage("550 Create directory operation failed.");
  }
}

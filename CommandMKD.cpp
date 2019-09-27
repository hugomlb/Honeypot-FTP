#include "CommandMKD.h"
#include "DirectorySetException.h"
#include "CommandInvalid.h"

CommandMKD::CommandMKD(DirectorySet* directorySet, User* aUser) {
  directories = directorySet;
  user = aUser;
}

void CommandMKD::execute(std::string argument) {
  if (!argument.empty()) {
    makeDirectory(argument);
  } else {
    CommandInvalid commandInvalid;
    commandInvalid.execute("");
  }
}

void CommandMKD::makeDirectory(const std::string& aDirectoryName) {
  if (user -> isLogged(this)) {
    try {
      directories -> addDirectory(aDirectoryName);
      printMessage("257 " + aDirectoryName + " created");
    } catch (DirectorySetException &e) {
      printMessage("550 Create directory operation failed.");
    }
  }
}

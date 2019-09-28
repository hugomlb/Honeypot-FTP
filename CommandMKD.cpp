#include "CommandMKD.h"
#include "DirectorySetException.h"
#include "CommandInvalid.h"

CommandMKD::CommandMKD(DirectorySet* directorySet, User* aUser,
    ServerConfiguration* configuration) {
  directories = directorySet;
  user = aUser;
  mkdSuccess = configuration -> getValueOf("mkdSuccess");
  mkdFailed = configuration -> getValueOf("mkdFailed");
}

void CommandMKD::execute(std::string argument) {
  if (!argument.empty()) {
    makeDirectory(argument);
  } else {
    /*CommandInvalid commandInvalid;
    commandInvalid.execute("");*/
  }
}

void CommandMKD::makeDirectory(const std::string& aDirectoryName) {
  if (user -> isLogged(this)) {
    try {
      directories -> addDirectory(aDirectoryName);
      printMessage("257 " + aDirectoryName + " " + mkdSuccess);
    } catch (DirectorySetException &e) {
      printMessage("550 " + mkdFailed);
    }
  }
}

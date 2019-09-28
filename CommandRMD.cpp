#include "CommandRMD.h"
#include "DirectorySetException.h"
#include "CommandInvalid.h"

CommandRMD::CommandRMD(DirectorySet* directorySet, User* aUser,
                       ServerConfiguration* configuration) {
  directories = directorySet;
  user = aUser;
  rmdSuccess = configuration -> getValueOf("rmdSuccess");
  rmdFailed = configuration -> getValueOf("rmdFailed");
}

void CommandRMD::execute(std::string argument) {
  if(!argument.empty()) {
    removeDirectory(argument);
  } else{
    /*CommandInvalid commandInvalid;
    commandInvalid.execute("");*/
  }
}

void CommandRMD::removeDirectory(const std::string& aDirectoryName) {
  if(user -> isLogged(this)) {
    try {
      directories -> removeDirectory(aDirectoryName);
      printMessage("250 " + rmdSuccess);
    } catch (DirectorySetException &e) {
      printMessage("550 " + rmdFailed);
    }
  }
}


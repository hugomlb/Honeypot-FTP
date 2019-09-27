#ifndef _COMMAND_RMD_H_
#define _COMMAND_RMD_H_


#include <string>
#include "User.h"
#include "DirectorySet.h"
#include "Command.h"

class CommandRMD: public Command {
  private:
    DirectorySet* directories;
    User* user;

    void removeDirectory(const std::string& aDirectoryName);

  public:
    explicit CommandRMD(DirectorySet* directorySet, User* aUser);

    void execute(std::string argument) override ;
};


#endif

#ifndef _COMMANDMKD_H_
#define _COMMANDMKD_H_

#include "Command.h"
#include "DirectorySet.h"
#include "User.h"
#include <string>

class CommandMKD: public Command {
  private:
    DirectorySet* directories;
    User* user;

    void makeDirectory(const std::string& aDirectoryName);
  public:
    explicit CommandMKD(DirectorySet* directorySet, User* aUser);

    void execute(std::string argument) override;
};


#endif

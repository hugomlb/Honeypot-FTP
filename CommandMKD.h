#ifndef _COMMAND_MKD_H_
#define _COMMAND_MKD_H_

#include "Command.h"
#include "DirectorySet.h"
#include "User.h"
#include "ServerConfiguration.h"
#include <string>

class CommandMKD: public Command {
  private:
    DirectorySet* directories;
    User* user;
    std::string mkdSuccess;
    std::string mkdFailed;

    void makeDirectory(const std::string& aDirectoryName);
  public:
    explicit CommandMKD(DirectorySet* directorySet, User* aUser,
        ServerConfiguration* configuration);

    void execute(std::string argument) override;
};


#endif

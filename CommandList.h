#ifndef _COMMAND_LIST_H_
#define _COMMAND_LIST_H_

#include "Command.h"
#include "User.h"
#include "DirectorySet.h"
#include "ServerConfiguration.h"

class CommandList: public Command {
  private:
    DirectorySet* directories;
    User* user;
    std::string listBegin;
    std::string listEnd;
    void list();
  public:
    explicit CommandList(DirectorySet* directorySet, User* aUser,
        ServerConfiguration* configuration);

    void execute(std::string argument) override;
};


#endif

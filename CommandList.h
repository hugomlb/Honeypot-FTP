#ifndef _COMMAND_LIST_H_
#define _COMMAND_LIST_H_

#include "Command.h"
#include "User.h"
#include "DirectorySet.h"

class CommandList: public Command {
  private:
    DirectorySet* directories;
    User* user;

    void list();
  public:
    explicit CommandList(DirectorySet* directorySet, User* aUser);

    void execute(std::string argument) override;
};


#endif

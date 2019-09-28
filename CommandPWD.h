#ifndef _COMMAND_PWD_H_
#define _COMMAND_PWD_H_

#include "Command.h"
#include "User.h"
#include "ServerConfiguration.h"

class CommandPWD: public Command {
  private:
    User* user;
    std::string currentDirectoryMsg;

    void currentDirectory();
  public:
    explicit CommandPWD(User* aUser, ServerConfiguration* configuration);
    void execute(std::string argument) override;
};


#endif

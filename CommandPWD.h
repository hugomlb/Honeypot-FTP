#ifndef _COMMAND_PWD_H_
#define _COMMAND_PWD_H_

#include "Command.h"
#include "User.h"

class CommandPWD: public Command {
  private:
    User* user;

    void currentDirectory();
  public:
    explicit CommandPWD(User* aUser);
    void execute(std::string argument) override;
};


#endif

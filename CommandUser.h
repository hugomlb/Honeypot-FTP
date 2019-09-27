#ifndef _COMMAND_USER_H_
#define _COMMAND_USER_H_

#include "Command.h"
#include "User.h"

class CommandUser: public Command {
  private:
    User* user;

  public:
    explicit CommandUser(User *aUser);

    void execute(std::string argument) override;
};


#endif

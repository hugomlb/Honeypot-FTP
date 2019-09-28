#ifndef _COMMAND_USER_H_
#define _COMMAND_USER_H_

#include "Command.h"
#include "User.h"
#include "ServerConfiguration.h"

class CommandUser: public Command {
  private:
    User* user;
    std::string passRequired;

  public:
    explicit CommandUser(User* aUser, ServerConfiguration* configuration);

    void execute(std::string argument) override;
};


#endif

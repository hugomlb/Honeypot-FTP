#ifndef _COMMAND_PASS_H_
#define _COMMAND_PASS_H_

#include "User.h"
#include "Command.h"
#include "ServerConfiguration.h"

class CommandPass: public Command {
  private:
    User* user;
    std::string loginSuccess;
    std::string loginFailed;

    void logSuccess(int logState);

  public:
    explicit CommandPass(User* aUser, ServerConfiguration* configuration);

    void execute(std::string argument) override;
};

#endif

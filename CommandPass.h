#ifndef _COMMAND_PASS_H_
#define _COMMAND_PASS_H_

#include "User.h"
#include "Command.h"

class CommandPass: public Command {
  private:
    User* user;

    static void logSuccess(int logState);

  public:
    explicit CommandPass(User* aUser);

    void execute(std::string argument) override;
};


#endif

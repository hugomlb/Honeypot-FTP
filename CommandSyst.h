#ifndef _COMMAND_SYST_H_
#define _COMMAND_SYST_H_

#include "Command.h"
#include "User.h"

class CommandSyst: public Command {
  private:
    User* user;

    void systemInfo();
  public:
    explicit CommandSyst(User* aUser);

    void execute(std::string argument) override;
};


#endif

#ifndef _COMMAND_HELP_H_
#define _COMMAND_HELP_H_


#include <string>
#include "Command.h"

class CommandHelp: public Command {
  private:
    std::string commands;
  public:
    explicit CommandHelp(ServerConfiguration* configuration);

    void execute(std::string argument) override;
};


#endif //_COMMANDHELP_H_

#ifndef _COMMAND_WELCOME_H_
#define _COMMAND_WELCOME_H_

#include "Command.h"
#include "ServerConfiguration.h"

class CommandWelcome: public Command{
  private:
    std::string newClient;
  public:
    explicit CommandWelcome(ServerConfiguration* configuration);

    void execute(std::string argument) override ;
};

#endif
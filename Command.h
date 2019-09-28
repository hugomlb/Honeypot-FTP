#ifndef _COMMAND_H_
#define _COMMAND_H_


#include <string>
#include "ServerConfiguration.h"

class Command {
  private:
    std::string clientNotLogged;
  public:
    explicit Command(ServerConfiguration* configuration);

    virtual void execute(std::string argument) = 0;

    static void printMessage(const std::string& aMessage);

    void askForLogin();

    ~Command() = default;
};

#endif

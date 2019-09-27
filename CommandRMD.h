#ifndef _COMMAND_RMD_H_
#define _COMMAND_RMD_H_


#include <string>
#include "DirectorySet.h"
#include "Command.h"

class CommandRMD: public Command {
  private:
    std::string directoryName;
    DirectorySet* directories;

    void execute();

  public:
    explicit CommandRMD(DirectorySet* directorySet);

    void execute(std::string argument) override ;
};


#endif

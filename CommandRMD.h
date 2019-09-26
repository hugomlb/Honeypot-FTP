#ifndef _COMMAND_RMD_H_
#define _COMMAND_RMD_H_


#include <string>
#include "DirectorySet.h"
#include "Command.h"

class CommandRMD: public Command {
  private:
    std::string directoryName;
    DirectorySet* directories;

  public:
    explicit CommandRMD(std::string aDirectoryName, DirectorySet* directorySet);

    void execute() override ;
};


#endif

#ifndef _COMMANDMKD_H_
#define _COMMANDMKD_H_

#include "Command.h"
#include "DirectorySet.h"
#include <string>

class CommandMKD: public Command {
  private:
    std::string directoryName;
    DirectorySet* directories;
  public:
    explicit CommandMKD(std::string aDirectoryName, DirectorySet* directorySet);

    void execute() override;
};


#endif

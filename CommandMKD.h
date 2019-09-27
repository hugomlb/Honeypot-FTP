#ifndef _COMMANDMKD_H_
#define _COMMANDMKD_H_

#include "Command.h"
#include "DirectorySet.h"
#include <string>

class CommandMKD: public Command {
  private:
    std::string directoryName;
    DirectorySet* directories;

    void execute();
  public:
    explicit CommandMKD(DirectorySet* directorySet);

    void execute(std::string argument) override;
};


#endif

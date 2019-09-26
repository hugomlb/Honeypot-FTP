#ifndef _COMMAND_LIST_H_
#define _COMMAND_LIST_H_

#include "Command.h"
#include "DirectorySet.h"

class CommandList: public Command {
  private:
    DirectorySet* directories;
  public:
    explicit CommandList(DirectorySet* directorySet);

    void execute() override;
};


#endif

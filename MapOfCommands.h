#ifndef _MAP_OF_COMMANDS_H_
#define _MAP_OF_COMMANDS_H_

#include <string>
#include <unordered_map>
#include "Command.h"
#include "CommandPass.h"
#include "CommandUser.h"
#include "CommandRMD.h"
#include "CommandMKD.h"
#include "CommandQuit.h"
#include "CommandList.h"
#include "ServerConfiguration.h"
#include "CommandSyst.h"
#include "CommandPWD.h"

class MapOfCommands {
  private:
    std::unordered_map<std::string, Command*> commandMap;
    CommandList list;
    CommandQuit quit;
    CommandMKD make;
    CommandRMD remove;
    CommandUser user;
    CommandPass pass;
    CommandSyst syst;
    CommandPWD currentDirectory;

  public:
    MapOfCommands(User* aUser, DirectorySet* directorySet);

    void findAndExecute(const std::string& commandCode, std::string commandArgument);
};

#endif

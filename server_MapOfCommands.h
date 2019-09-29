#ifndef _MAP_OF_COMMANDS_H_
#define _MAP_OF_COMMANDS_H_

#include <string>
#include <unordered_map>
#include "server_Command.h"
#include "server_CommandPass.h"
#include "server_CommandUser.h"
#include "server_CommandRMD.h"
#include "server_CommandMKD.h"
#include "server_CommandQuit.h"
#include "server_CommandList.h"
#include "server_ServerConfiguration.h"
#include "server_CommandSyst.h"
#include "server_CommandPWD.h"
#include "server_CommandInvalid.h"
#include "server_CommandHelp.h"

class server_MapOfCommands {
  private:
    std::unordered_map<std::string, server_Command*> commandMap;
    server_CommandList list;
    server_CommandMKD make;
    server_CommandRMD remove;
    server_CommandUser user;
    server_CommandPass pass;
    server_CommandSyst syst;
    server_CommandPWD currentDirectory;
    server_CommandQuit quit;
    server_CommandInvalid invalid;
    server_CommandHelp help;

  public:
    server_MapOfCommands(server_User* aUser, server_DirectorySet* directorySet,
                         server_ServerConfiguration* configuration);

    server_Command* find(const std::string& commandCode);
};

#endif

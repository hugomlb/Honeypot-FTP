#include "server_MapOfCommands.h"
#include "server_CommandInvalid.h"

server_MapOfCommands::server_MapOfCommands(server_User *aUser, server_ProtectedDirectorySet *directories,
    server_ServerConfiguration* config): list(directories, aUser, config),
    make(directories, aUser, config), remove(directories, aUser, config),
    user(aUser, config), pass(aUser, config), syst(aUser, config),
    currentDirectory(aUser, config), quit(config), invalid(config),
    help(aUser, config) {
  commandMap["LIST"] = &list;
  commandMap["QUIT"] = &quit;
  commandMap["MKD"] = &make;
  commandMap["RMD"] = &remove;
  commandMap["USER"] = &user;
  commandMap["PASS"] = &pass;
  commandMap["PWD"] = &currentDirectory;
  commandMap["SYST"] = &syst;
  commandMap["INVALID"] = &invalid;
  commandMap["HELP"] = &help;
}

server_Command* server_MapOfCommands::find(const std::string& commandCode) {
  auto iterator = commandMap.find(commandCode);
  if (iterator != commandMap.end()) {
    return  iterator -> second;
  } else {
    iterator = commandMap.find("INVALID");
    return  iterator -> second;
  }
}

#include "MapOfCommands.h"

#include <utility>
#include "CommandInvalid.h"

MapOfCommands::MapOfCommands(User *aUser, DirectorySet *directories,
    ServerConfiguration* config): list(directories, aUser, config),
    make(directories, aUser, config), remove(directories, aUser, config),
    user(aUser, config), pass(aUser, config), syst(aUser, config),
    currentDirectory(aUser, config), quit(config), invalid(config),
    help(config) {
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

void MapOfCommands::findAndExecute(const std::string& commandCode,
                                   std::string commandArgument) {
  auto iterator = commandMap.find(commandCode);
  if (iterator != commandMap.end()) {
    iterator -> second -> execute(std::move(commandArgument));
  } else {
    iterator = commandMap.find("INVALID");
    iterator -> second -> execute("");
  }
}

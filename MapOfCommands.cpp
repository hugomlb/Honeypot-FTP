#include "MapOfCommands.h"

#include <utility>
#include "CommandInvalid.h"

MapOfCommands::MapOfCommands(User *aUser, DirectorySet *directories, ServerConfiguration* configuration):
list(directories, aUser, configuration), make(directories, aUser, configuration),
remove(directories,aUser, configuration), user(aUser, configuration), pass(aUser, configuration), syst(aUser, configuration),
currentDirectory(aUser, configuration), quit(configuration), invalid(configuration) {
  commandMap["LIST"] = &list;
  commandMap["QUIT"] = &quit;
  commandMap["MKD"] = &make;
  commandMap["RMD"] = &remove;
  commandMap["USER"] = &user;
  commandMap["PASS"] = &pass;
  commandMap["PWD"] = &currentDirectory;
  commandMap["SYST"] = &syst;
  commandMap["INVALID"] = &invalid;

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

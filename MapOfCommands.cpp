#include "MapOfCommands.h"

#include <utility>
#include "CommandInvalid.h"

MapOfCommands::MapOfCommands(User *aUser, DirectorySet *directories): list(directories, aUser), make(directories, aUser),
    remove(directories, aUser), user(aUser), pass(aUser), syst(aUser), currentDirectory(aUser){
  commandMap["LIST"] = &list;
  commandMap["QUIT"] = &quit;
  commandMap["MKD"] = &make;
  commandMap["RMD"] = &remove;
  commandMap["USER"] = &user;
  commandMap["PASS"] = &pass;
  commandMap["PWD"] = &currentDirectory;
  commandMap["SYST"] = &syst;
}

void MapOfCommands::findAndExecute(const std::string& commandCode,
                                   std::string commandArgument) {
  auto iterator = commandMap.find(commandCode);
  if (iterator != commandMap.end()) {
    iterator -> second -> execute(std::move(commandArgument));
  } else {
    CommandInvalid commandInvalid;
    commandInvalid.execute("");
  }
}

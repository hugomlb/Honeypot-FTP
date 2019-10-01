#include "server_MapOfCommands.h"
#include "server_CommandInvalid.h"

server_MapOfCommands::server_MapOfCommands(server_ProtectedDirectorySet *directories,
    server_ServerConfiguration* config): list(directories, config),
    make(directories, config), remove(directories, config),
    user(config), pass(config), syst(config),
    currentDirectory(config), quit(config), invalid(config),
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

server_Command* server_MapOfCommands::find(const std::string& commandCode) {
  auto iterator = commandMap.find(commandCode);
  if (iterator != commandMap.end()) {
    return  iterator -> second;
  } else {
    iterator = commandMap.find("INVALID");
    return  iterator -> second;
  }
}

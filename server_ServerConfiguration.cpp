#include <fstream>
#include <iostream>
#include "server_ServerConfiguration.h"

server_ServerConfiguration::server_ServerConfiguration(const char* fileName) {
  std::ifstream configFile(fileName, std::ifstream::in);
  std::string key;
  std::string value;
  while (!configFile.eof()) {
    getline(configFile, key, '=');
    getline(configFile, value);
    if (!configFile.fail()) {
      configuration[key] = value;
    }
  }
}

std::string server_ServerConfiguration::getValueOf(const std::string& key) {
  auto iterator = configuration.find(key);
  if (iterator != configuration.end()) {
    return configuration[key];
  } else {
    return std::string("Unsupported Message");
  }
}


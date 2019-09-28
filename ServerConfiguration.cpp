#include <fstream>
#include <iostream>
#include "ServerConfiguration.h"

ServerConfiguration::ServerConfiguration() {
  std::ifstream configFile("config.cfg", std::ifstream::in);
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

std::string ServerConfiguration::getValueOf(const std::string& key) {
  return configuration[key];
}

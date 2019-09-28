#ifndef _SERVER_CONFIGURATION_H_
#define _SERVER_CONFIGURATION_H_

#include <string>
#include <unordered_map>

class ServerConfiguration {
  private:
    std::unordered_map<std::string, std::string> configuration;
  public:
    ServerConfiguration();

    std::string getValueOf(const std::string& key);
};


#endif

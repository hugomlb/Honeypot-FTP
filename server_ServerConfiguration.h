#ifndef _SERVER_CONFIGURATION_H_
#define _SERVER_CONFIGURATION_H_

#include <string>
#include <unordered_map>

class server_ServerConfiguration {
  private:
    std::unordered_map<std::string, std::string> configuration;
  public:
    explicit server_ServerConfiguration(const char* fileName);

    std::string getValueOf(const std::string& key);
};


#endif

#ifndef _SERVER_USER_H_
#define _SERVER_USER_H_

#include <string>
#include "server_ServerConfiguration.h"

class server_User {
  private:
    bool validUserName;
    bool validPassword;
    bool wasLastCommandUser;
    std::string user;
    std::string password;
  public:
    explicit server_User(server_ServerConfiguration* configuration);

    int enterPassword(const std::string& aPassword);

    void enterUserName(const std::string& aUserName);

    void lastCommandWas(const std::string& aCommandCode);

    bool isLogged();
};


#endif

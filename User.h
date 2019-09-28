#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "Command.h"
#include "ServerConfiguration.h"

class User {
  private:
    bool validUserName;
    bool validPassword;
    bool wasLastCommandUser;
    std::string user;
    std::string password;
  public:
    explicit User(ServerConfiguration* configuration);

    int enterPassword(const std::string& aPassword);

    void enterUserName(const std::string& aUserName);

    void lastCommandWas(const std::string& aCommandCode);

    bool isLogged(Command* aCommand);
};


#endif

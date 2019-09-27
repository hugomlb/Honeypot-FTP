#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "Command.h"

class User {
  private:
    bool validUserName;
    bool validPassword;
    bool wasLastCommandUser;
    std::string name;
    std::string password;
  public:
    User(std::string userName, std::string password);

    int enterPassword(const std::string& aPassword);

    void enterUserName(const std::string& aUserName);

    void lastCommandWas(const std::string& aCommandCode);

    bool isLogged(Command* aCommand);
};


#endif

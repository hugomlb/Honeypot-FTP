#include <string>
#include <utility>
#include <iostream>
#include "User.h"

#define LOGGED 0
#define NOT_LOGGED -1

User::User(std::string userName, std::string password) {
  validPassword = false;
  validUserName = false;
  wasLastCommandUser = false;
  name = std::move(userName);
  this -> password = std::move(password);
}

bool User::isLogged() {
  bool answer = true;
  if (!(validUserName && validPassword)) {
    std::cout << "530 Please login with USER and PASS." << std::endl;
    answer = false;
  }
  return answer;
}

int User::enterPassword(const std::string &aPassword) {
  if ((aPassword == password) && wasLastCommandUser && validUserName) {
    validPassword = true;
    return  LOGGED;
  } else {
    validUserName = false;
    return NOT_LOGGED;
  }
}

void User::enterUserName(const std::string &aUserName) {
  if (aUserName == name) {
    validUserName = true;
  }
}

void User::lastCommandWas(const std::string& aCommandCode) {
  wasLastCommandUser = aCommandCode == "USER";
}

#include <string>
#include <utility>
#include <iostream>
#include "User.h"

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

void User::enterPassword(const std::string &aPassword) {
  if (aPassword == password && wasLastCommandUser) {
    validPassword = true;
    std::cout << "230 Login successful." << std::endl;
  } else {
    std::cout << "530 Login incorrect." << std::endl;
  }
}

void User::enterUserName(const std::string &aUserName) {
  if (aUserName == name) {
    validUserName = true;
  }
  std::cout << "331 Please specify the password." << std::endl;
}

void User::lastCommandWas(const std::string& aCommandCode) {
  wasLastCommandUser = aCommandCode == "USER";
}

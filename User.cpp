#include <string>
#include <utility>
#include <iostream>
#include "User.h"

User::User(std::string userName, std::string password) {
  loginValid = false;
  this -> name = std::move(userName);
  this -> password = std::move(password);
}

void User::login(const std::string& aPassword) {
  if (aPassword == this -> password) {
    loginValid = true;
    std::cout << "230 Login successful." << std::endl;
  } else {
    std::cout << "530 Login incorrect." << std::endl;
  }
}

bool User::isLogged() {
  if (!loginValid) {
    std::cout << "530 Please login with USER and PASS." << std::endl;
  }
  return loginValid;
}

#include <string>
#include "server_User.h"

#define LOGGED 0
#define NOT_LOGGED -1

server_User::server_User(server_ServerConfiguration* configuration) {
  validPassword = false;
  validUserName = false;
  wasLastCommandUser = false;
  user = configuration -> getValueOf("user");
  this -> password = configuration -> getValueOf("password");
}

bool server_User::isLogged() {
  bool answer = true;
  if (!(validUserName && validPassword)) {
    answer = false;
  }
  return answer;
}

int server_User::enterPassword(const std::string &aPassword) {
  if ((aPassword == password) && wasLastCommandUser && validUserName) {
    validPassword = true;
    return  LOGGED;
  } else {
    validUserName = false;
    return NOT_LOGGED;
  }
}

void server_User::enterUserName(const std::string &aUserName) {
  if (aUserName == user) {
    validUserName = true;
  }
}

void server_User::lastCommandWas(const std::string& aCommandCode) {
  wasLastCommandUser = aCommandCode == "USER";
}

server_User::~server_User() {
}

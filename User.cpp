#include <string>
#include "User.h"

#define LOGGED 0
#define NOT_LOGGED -1

User::User(ServerConfiguration* configuration) {
  validPassword = false;
  validUserName = false;
  wasLastCommandUser = false;
  user = configuration -> getValueOf("user");
  this -> password = configuration -> getValueOf("password");
}

bool User::isLogged(Command* command, SocketPeer* socketPeer) {
  bool answer = true;
  if (!(validUserName && validPassword)) {
    command -> askForLogin(socketPeer);
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
  if (aUserName == user) {
    validUserName = true;
  }
}

void User::lastCommandWas(const std::string& aCommandCode) {
  wasLastCommandUser = aCommandCode == "USER";
}

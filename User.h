#ifndef _USER_H_
#define _USER_H_


class User {
  private:
    bool loginValid;
    std::string name;
    std::string password;
  public:
    User(std::string userName, std::string password);

    void login(const std::string& aPassword);

    bool isLogged();
};


#endif

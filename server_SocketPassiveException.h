//
// Created by hugo on 29/9/19.
//

#ifndef _SERVER_SOCKETPASSIVEEXCEPTION_H_
#define _SERVER_SOCKETPASSIVEEXCEPTION_H_

#include <stdexcept>

class server_SocketPassiveException: public std::runtime_error {
public:
  explicit server_SocketPassiveException(const std::string &arg);
};


#endif //_SERVER_SOCKETPASSIVEEXCEPTION_H_

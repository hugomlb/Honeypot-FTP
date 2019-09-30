#ifndef _SOCKET_PASSIVE_EXCEPTION_H_
#define _SOCKET_PASSIVE_EXCEPTION_H_

#include <stdexcept>

class server_SocketPassiveException: public std::runtime_error {
public:
  explicit server_SocketPassiveException(const std::string &arg);
};


#endif
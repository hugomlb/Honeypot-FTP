#ifndef _DIRECTORY_SET_EXCEPTION_H_
#define _DIRECTORY_SET_EXCEPTION_H_


#include <stdexcept>

class server_ProtectedDirectorySetException: public std::runtime_error {
  public:
    explicit server_ProtectedDirectorySetException(const std::string &arg);
};


#endif

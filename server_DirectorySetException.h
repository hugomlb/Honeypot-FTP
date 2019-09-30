#ifndef _DIRECTORY_SET_EXCEPTION_H_
#define _DIRECTORY_SET_EXCEPTION_H_


#include <stdexcept>

class server_DirectorySetException: public std::runtime_error {
  public:
    explicit server_DirectorySetException(const std::string &arg);
};


#endif

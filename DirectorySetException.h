#ifndef _DIRECTORY_SET_EXCEPTION_H_
#define _DIRECTORY_SET_EXCEPTION_H_


#include <stdexcept>

class DirectorySetException : public std::runtime_error {
  public:
    explicit DirectorySetException(const std::string &arg);
};


#endif

#include "DirectorySetException.h"

DirectorySetException::DirectorySetException(const std::string &arg)
    : runtime_error(arg) {

}

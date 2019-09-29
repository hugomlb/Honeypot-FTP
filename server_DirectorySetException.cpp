#include "server_DirectorySetException.h"

server_DirectorySetException::server_DirectorySetException(const std::string &arg)
    : runtime_error(arg) {
}

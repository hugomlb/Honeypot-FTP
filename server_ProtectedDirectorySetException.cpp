#include "server_ProtectedDirectorySetException.h"

server_ProtectedDirectorySetException::server_ProtectedDirectorySetException(
    const std::string &arg) : runtime_error(arg) {

}

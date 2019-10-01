#include "server_ProtectedDirectorySetException.h"

server_ProtectedDirectorySetException::server_ProtectedDirectorySetException(
    conststd::string &arg)
    : runtime_error(arg) {
}

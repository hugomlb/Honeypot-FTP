#include "server_SocketPassiveException.h"

server_SocketPassiveException::server_SocketPassiveException(
    const std::string &arg) : runtime_error(arg) {

}

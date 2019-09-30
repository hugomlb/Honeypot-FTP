#include "common_SocketPeerException.h"

common_SocketPeerException::common_SocketPeerException(const std::string &arg)
    : runtime_error(arg) {

}

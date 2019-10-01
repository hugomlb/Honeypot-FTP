#include "server_Lock.h"

server_Lock::server_Lock(std::mutex &aMutex) : mutex(aMutex) {
  mutex.lock();
}

server_Lock::~server_Lock() {
  mutex.unlock();
}

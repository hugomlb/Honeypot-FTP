#include "common_Lock.h"

common_Lock::common_Lock(std::mutex &aMutex) : mutex(aMutex) {
  mutex.lock();
}

common_Lock::~common_Lock() {
  mutex.unlock();
}

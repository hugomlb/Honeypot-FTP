#ifndef TP2_LOCK_H
#define TP2_LOCK_H

#include <mutex>

class common_Lock {
  private:
    std::mutex& mutex;
  public:
    explicit common_Lock(std::mutex& aMutex);

    ~common_Lock();
};
#endif

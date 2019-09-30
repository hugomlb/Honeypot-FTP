#ifndef _LOCK_H_
#define _LOCK_H_

#include <mutex>

class common_Lock {
  private:
    std::mutex& mutex;
  public:
    explicit common_Lock(std::mutex& aMutex);

    ~common_Lock();
};
#endif

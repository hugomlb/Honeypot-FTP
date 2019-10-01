#ifndef _LOCK_H_
#define _LOCK_H_

#include <mutex>

class server_Lock {
  private:
    std::mutex& mutex;
  public:
    explicit server_Lock(std::mutex& aMutex);

    ~server_Lock();
};
#endif

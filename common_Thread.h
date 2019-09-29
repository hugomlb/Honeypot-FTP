#ifndef _COMMON_THREAD_H_
#define _COMMON_THREAD_H_

#include <thread>

class common_Thread {
  private:
    std::thread thread;

  public:
    common_Thread();

    common_Thread(const common_Thread&) = delete;

    common_Thread& operator=(const common_Thread&) = delete;

    common_Thread(common_Thread&& other);

    common_Thread& operator=(common_Thread &&other);

    virtual void run() = 0;

    void start();

    void join();

    virtual ~common_Thread();
};


#endif

#ifndef _SERVER_THREAD_H_
#define _SERVER_THREAD_H_

#include <thread>

class server_Thread {
  private:
    std::thread thread;

  public:
    server_Thread();

    server_Thread(const server_Thread&) = delete;

    server_Thread& operator=(const server_Thread&) = delete;

    server_Thread(server_Thread&& other);

    server_Thread& operator=(server_Thread &&other);

    virtual void run() = 0;

    void start();

    void join();

    virtual ~server_Thread();
};


#endif

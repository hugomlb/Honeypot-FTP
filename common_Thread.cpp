#include <iostream>
#include "common_Thread.h"

common_Thread::common_Thread() {
}

void common_Thread::start() {
  thread = std::thread(&common_Thread::run, this);
}

void common_Thread::join() {
  thread.join();
}

common_Thread::common_Thread(common_Thread &&other) {
  this -> thread = std::move(other.thread);
}

common_Thread& common_Thread::operator=(common_Thread &&other) {
  this -> thread = std::move(other.thread);
  return *this;
}

common_Thread::~common_Thread() {
  std::cout << "Joining de clase Thread" << std::endl;
}

#include <iostream>
#include "server_Thread.h"

server_Thread::server_Thread() {
}

void server_Thread::start() {
  thread = std::thread(&server_Thread::run, this);
}

void server_Thread::join() {
  thread.join();
}

server_Thread::server_Thread(server_Thread &&other) {
  this -> thread = std::move(other.thread);
}

server_Thread& server_Thread::operator=(server_Thread &&other) {
  this -> thread = std::move(other.thread);
  return *this;
}

server_Thread::~server_Thread() {
}

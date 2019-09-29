#ifndef _SERVER_SERVER_H_
#define _SERVER_SERVER_H_

#include <string>
#include <unordered_map>
#include <mutex>
#include <atomic>
#include "server_DirectorySet.h"
#include "server_MapOfCommands.h"
#include "server_SocketPassive.h"
#include "common_Thread.h"
#include "server_ConnectedClientVector.h"

class server_Server: public common_Thread {
  //Al recibir una 'q' de entrada standar, el servidor debe cerrarse
  private:
    std::mutex mutex;
    server_ServerConfiguration configuration;
    server_DirectorySet directories;
    server_SocketPassive* socketPassive;
    std::atomic<bool> keepRunning{};
    server_CommandWelcome welcome;
    server_ConnectedClientVector clients;

  public:
    explicit server_Server(const char* aService, const char* configurationFile,
        server_SocketPassive* socketPassive);

    void run();

    void stop(); //MEJORAR

    ~server_Server();
};

#endif

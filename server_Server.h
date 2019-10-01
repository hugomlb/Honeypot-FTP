#ifndef _SERVER_SERVER_H_
#define _SERVER_SERVER_H_

#include <string>
#include <unordered_map>
#include <atomic>
#include "server_ProtectedDirectorySet.h"
#include "server_MapOfCommands.h"
#include "server_SocketPassive.h"
#include "common_Thread.h"
#include "server_ClientProxyVector.h"
#include "server_CommandWelcome.h"
#include "server_ClientProxy.h"
#include <vector>

class server_Server: public common_Thread {
  private:
    server_ServerConfiguration configuration;
    server_ProtectedDirectorySet directories;
    server_SocketPassive* socketPassive;
    std::atomic<bool> keepRunning;
    std::vector<server_ClientProxy*> clients;

    void killAll();

    void clean();

  public:
    explicit server_Server(const char* aService, const char* configurationFile,
        server_SocketPassive* socketPassive);

    void run();

    void stop();

    ~server_Server();
};

#endif

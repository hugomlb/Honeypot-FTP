#include <iostream>
#include <utility>
#include "server_Server.h"
#include "server_CommandWelcome.h"
#include "server_Command.h"
#include "server_ClientProxy.h"
#include "server_SocketPassiveException.h"


server_Server::server_Server(const char* aService, const char* configurationFile,
    server_SocketPassive* aSocketPassive): configuration(configurationFile) {
  this -> socketPassive = aSocketPassive;
  this -> socketPassive -> bind(aService);
  this -> socketPassive -> listen();
  keepRunning = false;
}

void server_Server::run() {
  keepRunning = true;
  server_CommandWelcome welcome(&configuration);
  server_CommandWelcome command(&configuration);
  try {
    while (keepRunning) {
      common_SocketPeer socketPeer = std::move(socketPassive -> acceptClient());
      if (keepRunning) {
        clients.push_back(new server_ClientProxy(&configuration, &directories, std::move(socketPeer)));
        clients.back() -> welcomenClient(&welcome);
        clients.back() -> start();
      }
      clean();
    }
  } catch (server_SocketPassiveException &e) {
  }
}

void server_Server::stop() {
  keepRunning = false;
  killAll();
}

void server_Server::killAll() {
  int i = 0;
  while(!clients.empty()) {
    if (!clients[i] -> isDead()) {
      clients[i] -> kill();
    }
    clients[i] -> join();
    delete clients[i];
    clients.erase(clients.begin());
  }
}

server_Server::~server_Server() {
  if (!clients.empty()) {
    killAll();
  }
}

void server_Server::clean() {
  int i = 0;
  while(i < (int) clients.size()) {
    if (clients[i] -> isDead()) {
      clients[i] -> join();
      delete clients[i];
      clients.erase(clients.begin() + i);
    } else {
      i++;
    }
  }
}

#include <cstring>
#include "Client.h"
#include "Server.h"

int main(int argc, char const *argv[]) {
  if (strcmp(argv[1], "client") == 0) {
    Client client;
    client.run();
  } else if (strcmp(argv[1], "server") == 0) {
    Server server;
    server.run();
  }
  return 0;
}

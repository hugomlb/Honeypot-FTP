#include <cstring>
#include "server_Server.h"

int main(int argc, char const *argv[]) {
  if (strcmp(argv[1], "server") == 0) {
    server_Server server;
    server.run();
  }
  return 0;
}

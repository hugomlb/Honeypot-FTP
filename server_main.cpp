#include "server_Server.h"
#define VALID_AMOUNT_OF_PARAMETERS 3

int main(int argc, char const *argv[]) {
  if (argc == VALID_AMOUNT_OF_PARAMETERS) {
    server_Server server(argv[1], argv[2]);
    server.run();
  }
  return 0;
}

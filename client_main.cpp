#include <cstring>
#include "client_Client.h"

int main(int argc, char const *argv[]) {
  if (strcmp(argv[1], "client") == 0) {
    client_Client client;
    client.run();
  }
  return 0;
}

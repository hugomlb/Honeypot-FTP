#include "client_Client.h"

#define VALID_AMOUNT_OF_PARAMETERS 3

int main(int argc, char const *argv[]) {
  if (argc == VALID_AMOUNT_OF_PARAMETERS) {
    client_Client client;
    client.run(argv[1], argv[2]);
  }
  return 0;
}

#include "Client.h"
#include "SocketPassive.h"

int main() {

  Client client;
  client.run();
  return 0;
   /*
  SocketPassive socketPassive;
  socketPassive.bind();
  socketPassive.listen();
  socketPassive.acceptClient();*/
}

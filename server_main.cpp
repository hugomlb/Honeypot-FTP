#include <iostream>
#include "server_Server.h"
#define VALID_AMOUNT_OF_PARAMETERS 3

int main(int argc, char const *argv[]) {
  if (argc == VALID_AMOUNT_OF_PARAMETERS) {
    server_SocketPassive socketPassive;
    server_Server server(argv[1], argv[2], &socketPassive);
    server.start();
    std::string quit = " ";
    while (quit != "q") {
      getline(std::cin, quit);
    }
    std::cout << "Cerrando Socket" << std::endl;
    socketPassive.close();
    std::cout << "Cerrando Servidor" << std::endl;
    server.stop();
    std::cout << "Join" << std::endl;
    server.join();
    std::cout << "Despues del Join" << std::endl;
  }
  return 0;
}

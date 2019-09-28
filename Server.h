#ifndef _SERVER_H_
#define _SERVER_H_

#include <string>
#include <unordered_map>
#include "User.h"
#include "DirectorySet.h"
#include "MapOfCommands.h"

class Server {
  //Al recibir una 'q' de entrada standar, el servidor debe cerrarse
  /* El servidor debe leer la configuracion y los mensajes a retornar de
   * un archivo. NO se valida que se encuentren todas las claves necesarias,
   * en caso de faltar una clave es discrecion del desarrollador contemplar
   * ese caso. El archivo tiene un formato "clave=valor".
   * PREGUNTAR:
   *  Ejemplo de help
   *  Cuestiones sobre el archivo que entra
   *  Cuestiones de como es la comunicacion por sockets (del servidor al cliente)
   */
  private:
    User user;
    DirectorySet directories;
    MapOfCommands commands;

   // void help(); //Consultar

  public:
    Server();

    static void newClient();

    void executeCommand(const std::string& command);

    ~Server();
};

#endif

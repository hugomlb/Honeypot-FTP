#ifndef HONEYPOT_FTP_SERVER_H
#define HONEYPOT_FTP_SERVER_H

#include <string>
#include "User.h"
#include "DirectorySet.h"
class Server {
  //Al recibir una 'q' de entrada standar, el servidor debe cerrarse
  /* El servidor debe leer la configuracion y los mensajes a retornar de
   * un archivo. NO se valida que se encuentren todas las claves necesarias,
   * en caso de faltar una clave es discrecion del desarrollador contemplar
   * ese caso. El archivo tiene un formato "clave=valor". preguntar por el orden de
   * este archivo
   */
  private:
    User user;
    DirectorySet directories;
  public:
    Server();

    void newClient();

    void userLogin(const std::string& password);

    void syst();

    void list();

    void mkd(const std::string& aDirectoryName);

    void rmd(std::string aDirectoryName);

    void help();

    void quit();

    void invalidCommand();

};


#endif

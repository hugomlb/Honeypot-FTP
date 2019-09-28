#ifndef _SOCKET_PASSIVE_H_
#define _SOCKET_PASSIVE_H_


class SocketPassive {
  private:
    int fd;
  public:
    SocketPassive();

    void bind();

    void listen();

    void acceptClient();
};


#endif

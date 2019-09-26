#ifndef HONEYPOT_FTP_COMMAND_H
#define HONEYPOT_FTP_COMMAND_H


class Command {
  public:
    virtual void execute() = 0;

    void printMessage();
};


#endif

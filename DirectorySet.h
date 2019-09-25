#ifndef _DIRECTORY_SET_H_
#define _DIRECTORY_SET_H_

#include <set>
#include <string>

class DirectorySet {
  private:
    std::set<std::string> directories;
  public:
    DirectorySet();

    void addDirectory();

    void removeDirectory();
};


#endif

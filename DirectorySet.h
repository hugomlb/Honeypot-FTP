#ifndef _DIRECTORY_SET_H_
#define _DIRECTORY_SET_H_

#include <set>
#include <string>
#include <list>

class DirectorySet {
  private:
    std::set<std::string> directories;
    std::set<std::string>::iterator iterator;

    bool isItDuplicate(const std::string& directoryName);
  public:
    void addDirectory(const std::string& directoryName);

    void removeDirectory(const std::string& directoryName);

    std::list<std::string> getDirectoryList();
};


#endif

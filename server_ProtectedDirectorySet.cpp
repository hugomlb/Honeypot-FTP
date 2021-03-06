#include "server_ProtectedDirectorySet.h"
#include "server_ProtectedDirectorySetException.h"
#include "server_Lock.h"

void server_ProtectedDirectorySet::addDirectory(const std::string&
                                                directoryName) {
  server_Lock lock(mutex);
  if (isItDuplicate(directoryName)) {
    throw  server_ProtectedDirectorySetException("Add failed");
  }
  directories.insert(directoryName);
}

void server_ProtectedDirectorySet::removeDirectory(const std::string&
                                                    directoryName) {
  server_Lock lock(mutex);
  if (!isItDuplicate(directoryName)) {
    throw  server_ProtectedDirectorySetException("Remove failed");
  }
  directories.erase(directoryName);
}

bool server_ProtectedDirectorySet::isItDuplicate(const std::string&
                                                directoryName) {
  iterator = directories.find(directoryName);
  bool answer = false;
  if (iterator != directories.end()) {
    answer = true;
  }
  return answer;
}

std::list<std::string> server_ProtectedDirectorySet::getDirectoryList() {
  server_Lock lock(mutex);
  std::list<std::string> listOfDirectories;
  for (iterator = directories.begin(); iterator != directories.end();
  iterator++) {
    listOfDirectories.push_back(*iterator);
  }
  return listOfDirectories;
}

server_ProtectedDirectorySet::~server_ProtectedDirectorySet() {
}

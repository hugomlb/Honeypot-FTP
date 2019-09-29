#include <iostream>
#include "server_DirectorySet.h"
#include "server_DirectorySetException.h"

void server_DirectorySet::addDirectory(const std::string& directoryName) {
  if (isItDuplicate(directoryName)) {
    throw  server_DirectorySetException("Add failed");
  }
  directories.insert(directoryName);
}

void server_DirectorySet::removeDirectory(const std::string& directoryName) {
  if (!isItDuplicate(directoryName)) {
    throw  server_DirectorySetException("Remove failed");
  }
  directories.erase(directoryName);
}

bool server_DirectorySet::isItDuplicate(const std::string& directoryName) {
  iterator = directories.find(directoryName);
  bool answer = false;
  if (iterator != directories.end()) {
    answer = true;
  }
  return answer;
}

std::list<std::string> server_DirectorySet::getDirectoryList() {
  std::list<std::string> listOfDirectories;
  for (iterator = directories.begin(); iterator != directories.end(); iterator++) {
    listOfDirectories.push_back(*iterator);
  }
  return listOfDirectories;
}

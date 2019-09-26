#include <iostream>
#include "DirectorySet.h"
#include "DirectorySetException.h"

void DirectorySet::addDirectory(const std::string& directoryName) {
  if (isItDuplicate(directoryName)) {
    throw  DirectorySetException("Add failed");
  }
  directories.insert(directoryName);
}

void DirectorySet::removeDirectory(const std::string& directoryName) {
  if (!isItDuplicate(directoryName)) {
    throw  DirectorySetException("Remove failed");
  }
  directories.erase(directoryName);
}

bool DirectorySet::isItDuplicate(const std::string& directoryName) {
  iterator = directories.find(directoryName);
  bool answer = false;
  if (iterator != directories.end()) {
    std::cout << "YA hay" << std::endl;
    answer = true;
  }
  return answer;
}

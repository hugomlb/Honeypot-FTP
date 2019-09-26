#include <set>
#include <iostream>
#include "Client.h"

int main() {
  Client client;
  client.run();
  return 0;
}/*
int main()
{
  std::set<std::string> setOfNumbers;

  // Lets insert four elements
  setOfNumbers.insert("Bokita");
  setOfNumbers.insert("AAA");
  setOfNumbers.insert("hOL KHE ASE");
  setOfNumbers.insert("Amigo");
  setOfNumbers.insert("Bokita");

  std::set<std::string>::iterator iterator;
  iterator = setOfNumbers.find("Bokita");
  if (iterator != setOfNumbers.end()) {
    std::cout << "Esta bokita" << std::endl;
  } else {
    std::cout << "No esta bokita" << std::endl;
  }
  return 0;
}*/

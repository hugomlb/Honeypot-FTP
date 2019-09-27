#include "CommandInvalid.h"

void CommandInvalid::execute(std::string argument) {
  printMessage("500 Unknown command.");
}

#include "CommandInvalid.h"

void CommandInvalid::execute() {
  printMessage("500 Unknown command.");
}

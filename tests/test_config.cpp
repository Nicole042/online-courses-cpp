#include "src/config/Config.hpp"
#include <cassert>
#include <iostream>

using namespace config;

int main() {
  assert(Config::appName().size() > 0);
  assert(Config::tokenTTL() > 0);
  assert(Config::maxPayment() > 0);
  std::cout << "[Config Tests] OK\n";
}

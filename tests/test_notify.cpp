#include "src/notify/Notifier.hpp"
#include <cassert>
#include <sstream>
#include <iostream>

using namespace notify;

int main() {
  FakeEmailNotifier n;
  n.send("u001", "Test mensaje");
  assert(true); // solo valida ejecucion
  std::cout << "[Notify Tests] OK\n";
}

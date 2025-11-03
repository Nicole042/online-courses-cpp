#include "src/notify/Notifier.hpp"
#include "src/course/Statistics.hpp"
#include <cassert>
#include <iostream>

using namespace notify;
using namespace course;

int main() {
  FakeEmailNotifier mail;
  CourseStatistics stats;
  mail.send("userX", "Has completado tu curso");
  stats.recordEnrollment("C1");
  stats.updateProgress("C1", 0.9);
  stats.printSummary();
  assert(true);
  std::cout << "[Integration Notify-Course OK]\n";
}

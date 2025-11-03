#include "src/course/CourseService.hpp"
#include "src/course/Course.hpp"
#include "src/notify/Notifier.hpp"
#include "src/course/Statistics.hpp"
#include <cassert>
#include <iostream>

using namespace course;
using namespace notify;

class DummyPayment : public PaymentGateway {
public:
  bool charge(const std::string&, const std::string&, double) override { return true; }
};

int main() {
  CatalogRepository repo;
  DummyPayment pay;
  FakeEmailNotifier mailer;
  CourseService service(repo, pay, mailer);

  auto c = service.createCourse("C++ Basico", "Intro", 10.0);
  assert(c.title == "C++ Basico");

  c = service.publishCourse(c.id.value);
  assert(c.published == true);

  auto e = service.enroll("user1", c.id.value);
  assert(e.status == EnrollmentStatus::Active);

  e = service.addProgress(e.enrollmentId, 0.5);
  assert(e.progress > 0);

  auto stats = service.statistics();
  stats.recordEnrollment(c.id.value);
  stats.updateProgress(c.id.value, 0.7);
  stats.printSummary();

  std::cout << "[Course Tests] OK\n";
}

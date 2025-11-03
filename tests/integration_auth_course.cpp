#include "src/auth/AuthService.hpp"
#include "src/course/CourseService.hpp"
#include "src/notify/Notifier.hpp"
#include <cassert>
#include <iostream>

using namespace auth;
using namespace course;
using namespace notify;

class DummyPayment : public PaymentGateway {
public:
  bool charge(const std::string&, const std::string&, double) override { return true; }
};

int main() {
  UserRepository users;
  AuthService auth(users);
  CatalogRepository repo;
  DummyPayment pay;
  FakeEmailNotifier mail;
  CourseService courses(repo, pay, mail);

  auto u = auth.registerUser("Jose", "jose@mail.com", "pass123", UserRole::Student);
  auto c = courses.createCourse("Git Basico", "Aprende control de versiones", 5.0);
  c = courses.publishCourse(c.id.value);

  auto e = courses.enroll(u.id.value, c.id.value);
  assert(e.status == EnrollmentStatus::Active);

  e = courses.addProgress(e.enrollmentId, 0.8);
  assert(e.progress >= 0.8);

  std::cout << "[Integration Auth-Course OK]\n";
}

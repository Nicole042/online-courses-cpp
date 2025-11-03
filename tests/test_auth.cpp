#include "src/course/CourseService.hpp"
#include <cassert>
int main(){
  using namespace course;
  CatalogRepository repo; FakePaymentGateway pay; CourseService svc(repo, pay);
  auto c = svc.createCourse("Algoritmos","Base",5.0);
  c = svc.publishCourse(c.id.value);
  auto e = svc.enroll("user-1", c.id.value);
  assert(e.status==EnrollmentStatus::Active);
  e = svc.addProgress(e.enrollmentId, 0.6);
  assert(e.progress>0.59);
  return 0;
  auto stats = svc.statistics();
stats.recordEnrollment(c.id.value);
stats.updateProgress(c.id.value, 0.5);
stats.printSummary();

}


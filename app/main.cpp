#include "src/auth/AuthService.hpp"
#include "src/course/CourseService.hpp"
#include <iostream>
int main(){
  using namespace auth; using namespace course;
  UserRepository userRepo; AuthService auth(userRepo);
  CatalogRepository catalog; FakePaymentGateway pg; CourseService courses(catalog, pg);

  auto u = auth.registerUser("Ana","ana@example.com","secret",UserRole::Student);
  auto t = auth.login("ana@example.com","secret");
  std::cout<<"User "<<u.name<<" token="<<t<<"\n";

  auto c = courses.createCourse("C++ desde cero","Intro a C++17",10.0);
  c = courses.publishCourse(c.id.value);
  auto e = courses.enroll(u.id.value, c.id.value);
  e = courses.addProgress(e.enrollmentId, 0.4);
  std::cout<<"Enrollment "<<e.enrollmentId<<" progress="<<e.progress<<"\n";
  return 0;
}


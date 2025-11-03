int main() {
  using namespace auth;
  using namespace course;
  try {
    UserRepository userRepo;
    AuthService auth(userRepo);
    CatalogRepository catalog;
    FakePaymentGateway pg;
    CourseService courses(catalog, pg);

    auto u = auth.registerUser("Ana", "ana@example.com", "secret", UserRole::Student);
    auto token = auth.login("ana@example.com", "secret");
    std::cout << "Usuario: " << u.name << " Token: " << token << "\n";

    auto c = courses.createCourse("C++ desde cero", "Intro a C++", 10.0);
    c = courses.publishCourse(c.id.value);
    auto e = courses.enroll(u.id.value, c.id.value);
    e = courses.addProgress(e.enrollmentId, 0.3);
    std::cout << "Progreso: " << e.progress * 100 << "%\n";
  } catch (std::exception &ex) {
    std::cerr << "Error: " << ex.what() << "\n";
  }
}



#include "src/auth/AuthService.hpp"
#include "src/auth/User.hpp"
#include <cassert>
#include <iostream>

using namespace auth;

int main() {
  UserRepository repo;
  AuthService service(repo);

  try {
    // 1. registro correcto
    auto u = service.registerUser("Ana", "ana@example.com", "pass", UserRole::Student);
    assert(u.name == "Ana");

    // 2. login correcto
    auto token = service.login("ana@example.com", "pass");
    assert(token.size() > 5);

    // 3. error: email invalido
    bool error = false;
    try { service.registerUser("X", "malemail", "123", UserRole::Student); }
    catch (...) { error = true; }
    assert(error);

    // 4. password corto
    error = false;
    try { service.registerUser("User", "ok@mail.com", "1", UserRole::Student); }
    catch (...) { error = true; }
    assert(error);

    // 5. login con contraseña incorrecta
    error = false;
    try { service.login("ana@example.com", "wrong"); }
    catch (...) { error = true; }
    assert(error);

    std::cout << "[Auth Tests] OK\n";
  } catch (...) {
    std::cerr << "Error en Auth tests\n";
  }
}


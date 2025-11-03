#include "src/security/AccessControl.hpp"
#include "src/auth/User.hpp"
#include <cassert>
#include <iostream>

using namespace security;
using namespace auth;

int main() {
  assert(AccessControl::canCreateCourse(UserRole::Teacher));
  assert(!AccessControl::canCreateCourse(UserRole::Student));
  assert(AccessControl::canManageUsers(UserRole::Admin));
  std::cout << "[Security Tests] OK\n";
}

#include "src/security/AccessControl.hpp"
#include "src/auth/User.hpp"
#include <cassert>

int main() {
  using security::AccessControl;
  using auth::UserRole;

  assert(AccessControl::canCreateCourse(UserRole::Teacher));
  assert(AccessControl::canCreateCourse(UserRole::Admin));
  assert(!AccessControl::canCreateCourse(UserRole::Student));

  assert(AccessControl::canManageUsers(UserRole::Admin));
  assert(!AccessControl::canManageUsers(UserRole::Teacher));
  assert(!AccessControl::canManageUsers(UserRole::Student));
  return 0;
}

#pragma once
#include "src/auth/User.hpp"

namespace security {

class AccessControl {
public:
  static bool canCreateCourse(auth::UserRole role) {
    return role == auth::UserRole::Teacher || role == auth::UserRole::Admin;
  }
  static bool canManageUsers(auth::UserRole role) {
    return role == auth::UserRole::Admin;
  }
};

} 

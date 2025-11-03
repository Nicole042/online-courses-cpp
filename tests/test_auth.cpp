#include "src/auth/AuthService.hpp"
#include <cassert>
int main(){
  using namespace auth;
  UserRepository r; AuthService s(r);
  auto u=s.registerUser("Luis","luis@example.com","pw",UserRole::Student);
  auto tok=s.login("luis@example.com","pw");
  assert(!tok.empty()); assert(s.validateToken(tok));
  bool bad=false; try{s.login("luis@example.com","bad");}catch(...){bad=true;}
  assert(bad); return 0;
}

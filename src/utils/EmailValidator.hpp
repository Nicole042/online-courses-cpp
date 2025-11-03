#pragma once
#include <string>

namespace utils {

class EmailValidator {
public:
  static bool isValid(const std::string& e) {
    auto at = e.find('@');
    if (at == std::string::npos || at == 0 || at == e.size()-1) return false;
    auto dot = e.find('.', at + 1);
    return dot != std::string::npos && dot > at + 1 && dot < e.size()-1;
  }
};

} 

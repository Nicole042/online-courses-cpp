#pragma once
#include <string>
#include <cstdlib>

namespace config {

class Config {
public:
  static std::string appName() { return getEnv("APP_NAME", "Online Courses C++"); }
  static int tokenTTL() { return stoi(getEnv("TOKEN_TTL", "3600")); }
  static double maxPayment() { return stod(getEnv("MAX_PAYMENT", "9999.0")); }

private:
  static std::string getEnv(const char* key, const char* def) {
    const char* v = std::getenv(key);
    return v ? std::string(v) : std::string(def);
  }
};

} 
#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

namespace utils {

class Logger {
public:
  static void info(const std::string& msg) {
    std::cout << "[INFO] " << timestamp() << " - " << msg << "\n";
  }
  static void error(const std::string& msg) {
    std::cerr << "[ERROR] " << timestamp() << " - " << msg << "\n";
  }

private:
  static std::string timestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    char buf[20];
    strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&t));
    return buf;
  }
};

} 

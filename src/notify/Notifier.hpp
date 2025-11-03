#pragma once
#include <string>
#include <iostream>

namespace notify {

class Notifier {
public:
  virtual ~Notifier() = default;
  virtual void send(const std::string& userId, const std::string& message) = 0;
};

class FakeEmailNotifier : public Notifier {
public:
  void send(const std::string& userId, const std::string& message) override {
    std::cout << "[Email] to=" << userId << " msg=" << message << "\n";
  }
};

} 
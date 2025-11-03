#pragma once
#include <string>
#include <stdexcept>
namespace course {
struct CourseId { std::string value; };
struct Course {
  CourseId id; std::string title; std::string description; double price; bool published{false};
  void publish(){ if (title.empty()) throw std::runtime_error("title required"); published=true; }
};
} 

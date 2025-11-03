#pragma once
#include "Course.hpp"
#include "Enrollment.hpp"
#include <string>

namespace course {

inline std::string toJson(const Course& c) {
  return std::string("{\"id\":\"") + c.id.value + "\",\"title\":\"" + c.title +
         "\",\"price\":" + std::to_string(c.price) + ",\"published\":" +
         (c.published ? "true" : "false") + "}";
}

inline std::string toJson(const Enrollment& e) {
  return std::string("{\"enrollmentId\":\"") + e.enrollmentId +
         "\",\"userId\":\"" + e.userId + "\",\"courseId\":\"" + e.courseId +
         "\",\"status\":\"" +
         (e.status==EnrollmentStatus::Active?"Active":e.status==EnrollmentStatus::Pending?"Pending":"Cancelled") +
         "\",\"progress\":" + std::to_string(e.progress) + "}";
}

} 

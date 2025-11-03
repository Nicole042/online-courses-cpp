#pragma once
#include <string>
#include <stdexcept>
namespace course {
enum class EnrollmentStatus { Pending, Active, Cancelled };
struct Enrollment {
  std::string enrollmentId; std::string userId; std::string courseId;
  EnrollmentStatus status{EnrollmentStatus::Pending}; double progress{0.0};
  void confirm(){ if(status!=EnrollmentStatus::Pending) throw std::runtime_error("invalid state"); status=EnrollmentStatus::Active; }
  void cancel(){ status=EnrollmentStatus::Cancelled; }
  void addProgress(double d){ if(status!=EnrollmentStatus::Active) throw std::runtime_error("not active"); progress+=d; if(progress>1.0) progress=1.0; }
};
} 
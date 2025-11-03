#pragma once
#include "Course.hpp"
#include "Enrollment.hpp"
#include <unordered_map>
#include <optional>
#include <random>

namespace course {
class CatalogRepository {
  public:
    Course save(Course c){ byId[c.id.value]=c; return c; }
    Course create(const std::string& title, const std::string& desc, double price){
      Course c{CourseId{genId()}, title, desc, price, false}; return save(c);
    }
    std::optional<Course> findCourse(const std::string& id) const {
      auto it=byId.find(id); if(it==byId.end()) return std::nullopt; return it->second;
    }
    Enrollment save(Enrollment e){ enrolls[e.enrollmentId]=e; return e; }
    Enrollment createEnrollment(const std::string& userId,const std::string& courseId){
      Enrollment e{genId(), userId, courseId, EnrollmentStatus::Pending, 0.0}; return save(e);
    }
    std::optional<Enrollment> findEnrollment(const std::string& id) const {
      auto it=enrolls.find(id); if(it==enrolls.end()) return std::nullopt; return it->second;
    }
    void updateEnrollment(const Enrollment& e){ enrolls[e.enrollmentId]=e; }
  private:
    std::unordered_map<std::string, Course> byId;
    std::unordered_map<std::string, Enrollment> enrolls;
    static std::string genId(){
      static std::mt19937_64 rng{std::random_device{}()};
      static const char* cs="abcdef0123456789"; std::string s(16,'0'); for(auto& c:s) c=cs[rng()%16]; return s;
    }
};
} 
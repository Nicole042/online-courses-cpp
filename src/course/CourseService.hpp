#pragma once
#include "CatalogRepository.hpp"
#include <stdexcept>
#include "Statistics.hpp"


namespace course {
class PaymentGateway {
  public: virtual ~PaymentGateway()=default;
  virtual bool charge(const std::string&, const std::string&, double)=0;
};
class FakePaymentGateway : public PaymentGateway {
  public: bool charge(const std::string&, const std::string&, double amount) override {
    return amount <= 9999.0;
  }
  private:
  CatalogRepository& repo;
  PaymentGateway& pg;
  CourseStatistics stats; // nuevo

public:
  CourseStatistics& statistics() { return stats; } // getter

};
class CourseService {
  public:
    CourseService(CatalogRepository& r, PaymentGateway& p): repo(r), pg(p) {}
    Course createCourse(const std::string& title, const std::string& desc, double price){
      if(title.size()<3) throw std::runtime_error("title too short");
      if(price<0) throw std::runtime_error("invalid price");
      return repo.create(title, desc, price);
    }
    Course publishCourse(const std::string& id){
      auto c=repo.findCourse(id); if(!c) throw std::runtime_error("course not found");
      auto course=*c; course.publish(); return repo.save(course);
    }
    Enrollment enroll(const std::string& userId, const std::string& courseId){
      auto c=repo.findCourse(courseId); if(!c) throw std::runtime_error("course not found");
      if(!c->published) throw std::runtime_error("course not published");
      auto e=repo.createEnrollment(userId, courseId);
      if(c->price>0.0){ if(!pg.charge(userId,courseId,c->price)){ e.cancel(); repo.updateEnrollment(e); throw std::runtime_error("payment declined"); } }
      e.confirm(); repo.updateEnrollment(e); return e;
      e.confirm();
    repo.updateEnrollment(e);
    stats.recordEnrollment(courseId);
    return e;
 }
    Enrollment addProgress(const std::string& enrollmentId, double delta){
      auto e=repo.findEnrollment(enrollmentId); if(!e) throw std::runtime_error("enrollment not found");
      auto up=*e; up.addProgress(delta); repo.updateEnrollment(up); return up;
    }
  private: CatalogRepository& repo; PaymentGateway& pg;
};
} 
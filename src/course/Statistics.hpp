#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

namespace course {

class CourseStatistics {
  std::unordered_map<std::string, int> enrollCount;
  std::unordered_map<std::string, double> avgProgress;

public:
  void recordEnrollment(const std::string& courseId) {
    enrollCount[courseId]++;
  }

  void updateProgress(const std::string& courseId, double progress) {
    avgProgress[courseId] = (avgProgress[courseId] + progress) / 2.0;
  }

  void printSummary() const {
    std::cout << "\n--- Estadísticas de cursos ---\n";
    for (auto& p : enrollCount) {
      std::cout << "Curso: " << p.first
                << " | Inscritos: " << p.second
                << " | Promedio progreso: " << (avgProgress.at(p.first) * 100)
                << "%\n";
    }
  }
};

} 

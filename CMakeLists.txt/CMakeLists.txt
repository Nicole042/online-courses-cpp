cmake_minimum_required(VERSION 3.16)
project(online_courses_cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(auth
  src/auth/User.hpp
  src/auth/UserRepository.hpp
  src/auth/PasswordHasher.hpp
  src/auth/TokenService.hpp
  src/auth/AuthService.hpp
)
target_include_directories(auth PUBLIC src)

add_library(course
  src/course/Course.hpp
  src/course/Enrollment.hpp
  src/course/CatalogRepository.hpp
  src/course/CourseService.hpp
)
target_include_directories(course PUBLIC src)

add_executable(app app/main.cpp)
target_link_libraries(app PRIVATE auth course)

add_executable(test_auth tests/test_auth.cpp)
target_link_libraries(test_auth PRIVATE auth)

add_executable(test_course tests/test_course.cpp)
target_link_libraries(test_course PRIVATE course auth)

enable_testing()
add_test(NAME test_auth COMMAND test_auth)
add_test(NAME test_course COMMAND test_course)


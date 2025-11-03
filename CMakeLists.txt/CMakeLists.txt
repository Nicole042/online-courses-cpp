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

add_executable(test_auth tests/test_auth.cpp)
add_executable(test_course tests/test_course.cpp)
add_executable(test_notify tests/test_notify.cpp)
add_executable(test_security tests/test_security.cpp)
add_executable(test_config tests/test_config.cpp)
add_executable(integration_auth_course tests/integration_auth_course.cpp)
add_executable(integration_notify_course tests/integration_notify_course.cpp)

add_test(NAME test_auth COMMAND test_auth)
add_test(NAME test_course COMMAND test_course)
add_test(NAME test_notify COMMAND test_notify)
add_test(NAME test_security COMMAND test_security)
add_test(NAME test_config COMMAND test_config)
add_test(NAME integration_auth_course COMMAND integration_auth_course)
add_test(NAME integration_notify_course COMMAND integration_notify_course)




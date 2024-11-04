cmake_minimum_required(VERSION 3.8)
project(RK4 CXX)

# find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# include_directories(C:/UTIL/eigen-3.4.0)

# add_executable(RK4 sim_runge_kutta.cpp)
add_executable(${CMAKE_PROJECT_NAME} sim_runge_kutta.cpp controller.cpp dynamics.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE C:/UTIL/eigen-3.4.0)
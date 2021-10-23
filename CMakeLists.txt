cmake_minimum_required(VERSION 3.20)
project(tp_hw_c_cpp_2021_2)

set(CMAKE_C_STANDARD 99)

# Flags to generate test coverage
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

# Make task library
add_library(lib STATIC src/functions.c)
target_include_directories(lib PUBLIC include)

# Make executable program
add_executable(hw-1 src/main.c)
target_link_libraries(hw-1 lib)

enable_testing()

# Find libraries for test
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Make executable test program
add_executable(test.out test/gtest.cpp)
target_link_libraries(test.out lib ${GTEST_LIBRARIES} Threads::Threads)
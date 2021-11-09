cmake_minimum_required(VERSION 3.20)
project(tp_hw_c_cpp_2021_2)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

set(SOURCE_DIRECTORY source)
set(INCLUDE_DIRECTORY include)

find_package(Threads REQUIRED)

add_library(lib_multi_thread SHARED ${SOURCE_DIRECTORY}/multi_thread.c)
target_include_directories(lib_multi_thread PUBLIC include)

add_library(lib_one_thread STATIC ${SOURCE_DIRECTORY}/one_thread.c)
target_include_directories(lib_one_thread PUBLIC include)

enable_testing()

find_package(GTest REQUIRED)

add_executable(test_one_thread.out tests/gtest_one_thread.cpp)
target_link_libraries(test_one_thread.out lib_one_thread ${GTEST_LIBRARIES} Threads::Threads)

add_executable(test_multi_thread.out tests/gtest_multi_thread.cpp)
target_link_libraries(test_multi_thread.out lib_multi_thread ${GTEST_LIBRARIES} Threads::Threads)
#include "../include/stress_tests.h"

int comparator(const char* file_name) {
    int one_thread_result = stress_test_one_thread(file_name);
    int multi_thread_result = stress_test_multi_thread(file_name);
    if (one_thread_result == multi_thread_result) {
        return 0;
    }
    return -1;
}
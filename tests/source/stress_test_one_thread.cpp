#include "../include/stress_tests.h"
#include "../../include/one_thread.h"

int stress_test_one_thread(const char *file_name) {
    return counter(file_name);
}


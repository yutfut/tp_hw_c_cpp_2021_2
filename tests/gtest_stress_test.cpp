#include <gtest/gtest.h>

extern "C" {
    #include "include/stress_tests.h"
}

TEST(STRESS_TEST, stress_test) {
    EXPECT_EQ(comparator((char *)"../cmake-build-debug/data_1.txt"), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
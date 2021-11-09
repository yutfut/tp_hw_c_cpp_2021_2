#include <gtest/gtest.h>

extern "C" {
    #include "../include/one_thread.h"
}

TEST(FILE_TEST, file_exists) {
    EXPECT_EQ(counter((char *)"../cmake-build-debug/data.txt"), 1057);
}

TEST(FILE_TEST, file_dont_exists) {
    EXPECT_EQ(counter((char *)""), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
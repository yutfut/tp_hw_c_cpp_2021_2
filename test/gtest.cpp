#include <gtest/gtest.h>

extern "C" {
    #include "../include/header.h"
}

TEST(FUNCTION_TEST, allocate_test) {
    struct project new_project = {0, NULL};
    EXPECT_EQ(sizeof(create()), sizeof(&new_project));
}

TEST(FUNCTION_TEST, equal_test) {
    struct project new_project = {0, NULL};
    struct project *test_p = create();
    EXPECT_EQ(test_p->size, new_project.size);
    EXPECT_EQ(test_p->members, new_project.members);
}

TEST(FUNCTION_TEST, print_test) {
    struct people member = {(char *) "name",
                            (char *) "surname",
                            (char *) "role",
                            34,
                            5.5};
    EXPECT_EQ(print(&member), 0);
}

TEST(FUNCTION_TEST, no_print_test) {
    struct people *member = NULL;
    EXPECT_EQ(print(member), 1);
}

TEST(FUNCTION_TEST, selected_test) {
    struct people member = {(char *) "name",
                            (char *) "surname",
                            (char *) "role",
                            34,
                            5.5};
    struct project new_project = {1, &member};
    EXPECT_EQ(selected(&new_project,
                       (char *) "role",
                       1,
                       2,
                       3,
                       4), 0);
}

TEST(FUNCTION_TEST, error_selected_test) {
    struct people *member = NULL;
    struct project new_project = {1, member};
    EXPECT_EQ(selected(&new_project,
                       (char *) "role",
                       1,
                       2,
                       3,
                       4), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
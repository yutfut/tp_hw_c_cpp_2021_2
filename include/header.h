#ifndef TP_HW_C_CPP_2021_2_HEADER_H
#define TP_HW_C_CPP_2021_2_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct people {
    char *name;
    char *surname;
    char *role;
    int age;
    double degrees_influence;
};

struct project {
    size_t size;
    struct people *members;
};

char input_char();

char *input_string();

int input_int();

double input_double();

int print(struct people * member);

int selected(const struct project * my_project,
            char* role, int low_age, int high_age,
            double low_degrees_influence, double high_degrees_influence);

int entering_selection_parameters(const struct project * my_project);

struct project * create_project();

struct people *create_members(size_t size);

int input_member(struct people *member);

int input_size(struct project *my_project);

int input(struct project *my_project);

void delete_project(struct project * my_project);

#endif //TP_HW_C_CPP_2021_2_HEADER_H


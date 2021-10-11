#ifndef TP_HW_C_CPP_2021_2_HEADER_H
#define TP_HW_C_CPP_2021_2_HEADER_H

#endif //TP_HW_C_CPP_2021_2_HEADER_H

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

void print(struct people * const member);

void select(const struct project * const my_project,
            char* role, int low_age, int high_age,
            double low_degrees_influence, double high_degrees_influence);

void entering_selection_parameters(const struct project * const my_project);

void create(struct project **my_project_p);
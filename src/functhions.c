#include "../include/header.h"

char input_char() {
    char c = '\0';
    int result = 0;
    do {
        result = scanf("%c", &c);
    } while (result != 1);
    return c;
}

char *input_string() {
    struct buffer {
        char *string;
        size_t size;
        size_t capacity;
    } buf = {NULL, 0, 0};
    char c = '\0';
    while (c = input_char(), c != EOF && c != '\n') {
        if (buf.size + 1 >= buf.capacity) {
            size_t new_capacity = !buf.capacity ? 1 : buf.capacity * 2;
            char *tmp = (char *)malloc((new_capacity + 1) * sizeof(char));
            if (!tmp) {
                if (buf.string) {
                    free(buf.string);
                }
                return NULL;
            }
            if (buf.string) {
                tmp = strcpy(tmp, buf.string);
                free(buf.string);
            }
            buf.string = tmp;
            buf.capacity = new_capacity;
        }
        buf.string[buf.size] = c;
        buf.string[buf.size + 1] = '\0';
        ++buf.size;
    }
    return buf.string;
}

int input_int() {
    char c = '\0';
    int result = 0;
    while (c = input_char(), c != EOF && c != '\n') {
        if (!(c >= '0' && c <= '9')) {
            char *buf = input_string(); /* Read to the end of the string */
            if (buf) {
                free(buf);
            }
            return 0;
        }
        result = result * 10 + c - 48;
    }
    return result;
}

double input_double() {
    double result = 0;
    char c = '\0';
    int dote = 1;
    int divider = 10;
    while (c = input_char(), c != EOF && c != '\n') {
        if (c >= '0' && c <= '9' && dote) {
            result = result * 10 + (c - 48);
        }
        if (c == '.') {
            dote = 0;
            continue;
        }
        if (c >= '0' && c <= '9' && !dote) {
            double buff = (double) (c - 48) / divider;
            result = result + buff;
            divider = divider * 10;
        }
    }
    return result;
}

void print(struct people * const member) {
    printf("%s %s %s %d %f\n",
           member->name,
           member->surname,
           member->role,
           member->age,
           member->degrees_influence);
}

void select(const struct project * const my_project,
               char* role, int first_age, int second_age,
               double first_degrees_influence, double second_degrees_influence) {
    for (size_t i = 0; i < my_project->size; ++i) {
        int bool = 1;
        if (strcmp (my_project->members[i].role, role) != 0) {
            bool = 0;
        }
        if (first_age > my_project->members[i].age  && my_project->members[i].age > second_age) {
            bool = 0;
        }
        if (first_degrees_influence > my_project->members[i].degrees_influence && my_project->members[i].degrees_influence > second_degrees_influence) {
            bool = 0;
        }
        if (bool == 1) {
            print(&my_project->members[i]);
        }
    }
}

void entering_selection_parameters(const struct project * const my_project) {
    char *role = NULL;
    int low_age = 0, high_age = 0;
    double low_degrees_influence = 0, high_degrees_influence = 0;
    printf("Введите роль\n");
    role = input_string();
    printf("Введите нижнию возрастную границу\n");
    low_age = input_int();
    printf("Введите верхнию возрастную границу\n");
    high_age = input_int();
    printf("Введите нижнию границу степени влияния\n");
    low_degrees_influence = input_double();
    printf("Введите верхнию границу степени влияния\n");
    high_degrees_influence = input_double();
    select(my_project, role, low_age, high_age, low_degrees_influence, high_degrees_influence);
}

void create(struct project **my_project_p) {
    *my_project_p = (struct project *)malloc(sizeof(struct project));
    struct project *my_project = *my_project_p;
    my_project->size = 0;
    my_project->members = NULL;

    printf("Введите размер команды\n");
    my_project->size = (size_t) input_int();

    my_project->members = (struct people *) malloc(my_project->size * sizeof(struct people));

    for (size_t i = 0; i < my_project->size; ++i) {
        printf("Введите name\n");
        my_project->members[i].name = input_string();
        printf("Введите surname\n");
        my_project->members[i].surname = input_string();
        printf("Введите role\n");
        my_project->members[i].role = input_string();
        printf("Введите age\n");
        my_project->members[i].age = input_int();
        printf("Введите degrees of influence\n");
        my_project->members[i].degrees_influence = input_double();
    }
}


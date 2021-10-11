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

int print(struct people * member) {
    if (!member)
        return 1;
    printf("%s %s %s %d %f\n",
           member->name,
           member->surname,
           member->role,
           member->age,
           member->degrees_influence);
    return 0;
}

int selected(const struct project * my_project,
              char* role, int first_age, int second_age,
              double first_degrees_influence, double second_degrees_influence) {
    for (size_t i = 0; i < my_project->size; ++i) {
        int bool = 0;
        if (strcmp (my_project->members[i].role, role) != 0) {
            bool = 1;
        }
        if (first_age > my_project->members[i].age  && my_project->members[i].age > second_age) {
            bool = 1;
        }
        if (first_degrees_influence > my_project->members[i].degrees_influence && my_project->members[i].degrees_influence > second_degrees_influence) {
            bool = 1;
        }
        if (bool == 0) {
            bool = print(&my_project->members[i]);
            if (bool == 1)
                return 1;
        }
    }
    return 0;
}

int entering_selection_parameters(const struct project * my_project) {
    char *role = NULL;
    int low_age = 0, high_age = 0;
    double low_degrees_influence = 0, high_degrees_influence = 0;
    printf("Введите роль\n");
    role = input_string();
    if (!role)
        return 1;
    printf("Введите нижнию возрастную границу\n");
    low_age = input_int();
    printf("Введите верхнию возрастную границу\n");
    high_age = input_int();
    printf("Введите нижнию границу степени влияния\n");
    low_degrees_influence = input_double();
    printf("Введите верхнию границу степени влияния\n");
    high_degrees_influence = input_double();
    return selected(my_project, role, low_age, high_age, low_degrees_influence, high_degrees_influence);
}

struct project *create() {
    struct project *my_project = (struct project *)malloc(sizeof(struct project));
    if (!my_project)
        return NULL;

    my_project->size = 0;
    my_project->members = NULL;
    return my_project;
}

int input(struct project *my_project) {
    printf("Введите размер команды\n");
    my_project->size = (size_t) input_int();
    my_project->members = (struct people *) malloc(my_project->size * sizeof(struct people));
    if (my_project->members == NULL)
        return 1;

    for (size_t i = 0; i < my_project->size; ++i) {
        my_project->members[i].name = NULL;
        my_project->members[i].surname = NULL;
        my_project->members[i].role = NULL;
        my_project->members[i].age = 0;
        my_project->members[i].degrees_influence = 0;

        printf("Введите name\n");
        my_project->members[i].name = input_string();
        if (!my_project->members[i].name)
            return 1;
        printf("Введите surname\n");
        my_project->members[i].surname = input_string();
        if (!my_project->members[i].surname)
            return 1;
        printf("Введите role\n");
        my_project->members[i].role = input_string();
        if (!my_project->members[i].role)
            return 1;
        printf("Введите age\n");
        my_project->members[i].age = input_int();
        if (my_project->members[i].age == 0)
            return 1;
        printf("Введите degrees of influence\n");
        my_project->members[i].degrees_influence = input_double();
        if (my_project->members[i].age == 0)
            return 1;
    }
    return 0;
}




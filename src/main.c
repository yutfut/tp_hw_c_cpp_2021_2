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

char *input_string() {
    struct string {
        char *string;
        size_t size;
    } string = {NULL, 0};
    char c = '\0';
    while (scanf("%c", &c), c != EOF && c != '\n') {
        string.size++;
        char *temple = (char *)malloc(string.size * sizeof(char));
        for (size_t i = 0; i < string.size - 1; ++i) {
            temple[i] = string.string[i];
        }
        string.string = temple;
        free(temple);
        string.string[string.size - 1] = c;
    }
    return string.string;
}

int input_int() {
    int result = 0;
    char c = '\0';
    while (scanf("%c", &c), c != EOF && c != '\n') {
        if (c >= '0' && c <= '9') {
            result = result * 10 + (c - 48);
        }
    }
    return result;
}

double input_double() {
    double result = 0;
    char c = '\0';
    int dote = 1;
    int divider = 10;
    while (scanf("%c", &c), c != EOF && c != '\n') {
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

int main() {
    printf("hello world\n");
    struct project *my_project = NULL;
    my_project = (struct project *) malloc(sizeof(struct project));
    my_project->size = (size_t) NULL;
    my_project->members = NULL;
    printf("Введите размер команды\n");
    int count_members = input_int();
    my_project->size = (size_t) count_members;
    my_project->members = (struct people *)malloc(my_project->size * sizeof(struct people));
    for (size_t i = 0; i < my_project->size; ++i) {
        my_project->members[i].name = input_string();
        my_project->members[i].surname = input_string();
        my_project->members[i].role = input_string();
        my_project->members[i].age = input_int();
        my_project->members[i].degrees_influence = input_double();
        printf("%zu %s %s %s %d %f\n", i,
               my_project->members[i].name,
               my_project->members[i].surname,
               my_project->members[i].role,
               my_project->members[i].age,
               my_project->members[i].degrees_influence);
    }
    return 0;
}
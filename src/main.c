#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct people{
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
            result = result * 10 + c - 48;
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
    char *s;
    printf("Введите размер команды\n");
    int count_members = input_int();
    printf("%d\n", count_members);
    my_project->size = (size_t) count_members;
    my_project->members = (struct people *)malloc(my_project->size * sizeof(struct people));
    printf("%lu %lu\n", sizeof(struct people), sizeof(my_project->members[1]));
    for (size_t i = 0; i < my_project->size; ++i) {
        my_project->members[i].name = NULL;
        my_project->members[i].surname = NULL;
        my_project->members[i].role = NULL;
        my_project->members[i].age = 0;
        my_project->members[i].degrees_influence = 0;
        s = input_string();
        my_project->members[i].name = s;
        s = input_string();
        my_project->members[i].surname = s;
        s = input_string();
        my_project->members[i].role = s;
        int age = 0;
        age = input_int();
        my_project->members[i].age = age;
        s = input_string();
        my_project->members[i].degrees_influence = (double) *s - 48;
        printf("%zu %s %s %s %d %lf\n", i,
               my_project->members[i].name,
               my_project->members[i].surname,
               my_project->members[i].role,
               my_project->members[i].age,
               my_project->members[i].degrees_influence);
    }
    free(s);
    return 0;
}
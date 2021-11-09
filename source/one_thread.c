// Copyright 2021 Golubev

#include "../include/one_thread.h"

int counter(const char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        return -1;
    }

    int val, sum = 0;

    while(fscanf(fp, "%d\n", &val) != EOF) {
        if((val < 0) || ((val < 157) && (val >= 100))) {
            sum++;
        }
    }

    fclose(fp);
    return sum;
}

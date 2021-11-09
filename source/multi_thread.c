// Copyright 2021 Golubev

#include "../include/multi_thread.h"

data_t data = {PTHREAD_MUTEX_INITIALIZER, 0};

void* check(void* args) {
    FILE *fp = args;
    int val;

    pthread_mutex_t *mutex = &data.mutex;
    while(fscanf(fp, "%d\n", &val) != EOF) {
        if((val < 0) || ((val < 157) && (val >= 100))) {
            pthread_mutex_lock(mutex);
            data.value += 1;
            pthread_mutex_unlock(mutex);
        }
    }
    return 0;
}

int counter(const char *file_name) {
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        return -1;
    }

    const int N = (int)sysconf(_SC_NPROCESSORS_ONLN);

    pthread_t threadIds[N];

    for (int i = 0; i < N; i++) {
        int errflag = pthread_create(&threadIds[i], NULL, check, fp);
        if (errflag != 0) {
            return -1;
        }
    }

    for (int i = 0; i < N; i++) {
        int errflag = pthread_join(threadIds[i], NULL);
        if (errflag != 0) {
            return -1;
        }
    }

    fclose(fp);
    return data.value;
}



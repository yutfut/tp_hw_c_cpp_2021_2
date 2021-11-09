#ifndef TP_HW_C_CPP_2021_2_MULTI_THREAD_HEADER_H
#define TP_HW_C_CPP_2021_2_MULTI_THREAD_HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
    int value;
} data_t;

void* check(void *args);

int counter(const char *file_name);

#endif //TP_HW_C_CPP_2021_2_MULTI_THREAD_HEADER_H

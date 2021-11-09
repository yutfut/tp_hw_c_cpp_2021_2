// Copyright 2021 Golubev

#ifndef INCLUDE_MULTI_THREAD_H_
#define INCLUDE_MULTI_THREAD_H_

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
    int value;
} data_t;

void* check(void *args);

int counter(const char *file_name);

#endif  // INCLUDE_MULTI_THREAD_H_

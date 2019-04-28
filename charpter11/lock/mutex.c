#include<stdio.h>
#include<pthread.h>
struct foo{
    int f_count;
    pthread_mutex_t f_lock;
    int f_id;
};


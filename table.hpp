#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

struct table{
    int data[2];
    int counter=0;
    sem_t semFull;
    sem_t semEmpty;
};
#endif
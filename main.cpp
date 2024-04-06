#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>
#include <iostream>

#include "producer.cpp"
#include "consumer.cpp"

#define maxBuffer 2
#define bufferSize 2

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int table[bufferSize];
pthread_mutex_t mutex;

int main(){
    pthread_t pro[2], con[2];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, bufferSize);
    sem_init(&full, 0, 0);

    int a[5] = { 1, 2 };

    for (int i = 0; i < 2; i++) {
        pthread_create(&pro[i], NULL, producer, (void*)&a[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_create(&con[i], NULL, consumer, (void*)&a[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(pro[i], NULL);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

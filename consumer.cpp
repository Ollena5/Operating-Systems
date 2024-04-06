
#include <pthread.h>
#include <semaphore.h>
#include <iostream>

#define maxBuffer 2
#define bufferSize 2

extern sem_t empty;
extern sem_t full;
extern int out;
extern int table[bufferSize];
extern pthread_mutex_t mutex;

void* consumer(void* con){
    for (int i = 0; i < maxBuffer; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = table[out];
        std::cout << "Consumer " << *((int*)con) << ": remove item " << item << " from " << out << std::endl;
        out = (out + 1) % bufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return nullptr;
}

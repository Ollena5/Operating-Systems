
#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>
#include <iostream>

#define maxBuffer 2
#define bufferSize 2

extern sem_t empty;
extern sem_t full;
extern int in;
extern int table[bufferSize];
extern pthread_mutex_t mutex;

void* producer(void* pro) {
    int item;
    for (int i = 0; i < maxBuffer; i++) {
        item = rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        table[in] = item;
        std::cout << "producer " << *((int*)pro) << ": insert Item " << table[in] << " at " << in << std::endl;
        in = (in + 1) % bufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return nullptr;
}

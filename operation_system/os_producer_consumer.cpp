#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

//using namespace std;
#define NUM_THREADS 2
#define NUM_BUFFER 10
#define NUM_CONSUMER 2
#define NUM_PRODUCER 2
#define NUM_PRODUCER_PRODUCTS 12
#define NUM_CONSUMER_PRODUCTS 12

sem_t empty, full;//producer生产消耗empty, consumer消费消耗full；
pthread_mutex_t lock_producer = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_consumer = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_stream = PTHREAD_MUTEX_INITIALIZER;
int buffers[NUM_BUFFER];
int index_ = 0;

void* producer(void* args){
    int *id = static_cast<int*>(args);
    int i = 0;
    while (i < NUM_PRODUCER_PRODUCTS){
        sem_wait(&empty);
//        std::cout<< "The producer "<< *id<< " produces an item"<< std::endl;
        pthread_mutex_lock(&lock_producer);

        index_ = (index_ + 1) % NUM_BUFFER;
        buffers[index_] = index_;
        pthread_mutex_lock(&lock_stream);
        std::cout<<"producer "<< *id <<" put item : "<< buffers[index_] << std::endl;
        pthread_mutex_unlock(&lock_stream);
        i++;
        pthread_mutex_unlock(&lock_producer);
//        std::cout<< "The producer "<< *id<< " go out!"<< std::endl;
        sem_post(&full);

    }
    pthread_exit(nullptr);
}

void* consumer(void* args){
    int *id = static_cast<int*>(args);
    int i = 0;
    while (i < NUM_CONSUMER_PRODUCTS){
        sem_wait(&full);
//        std::cout<< "The consumer "<< *id<< " consume an item"<< std::endl;
        pthread_mutex_lock(&lock_consumer);

        pthread_mutex_lock(&lock_stream);
        std::cout<<"consumer " << *id <<" consume item : "<< buffers[index_] << std::endl;
        pthread_mutex_unlock(&lock_stream);

        index_ = (index_ + NUM_BUFFER - 1) % NUM_BUFFER;
        i++;
        pthread_mutex_unlock(&lock_consumer);
//        std::cout<< "The consumer "<< *id<< " consume an item"<< std::endl;
        sem_post(&empty);
    }
    pthread_exit(nullptr);
}

int main(){
    sem_init(&empty, 0, NUM_BUFFER);
    sem_init(&full, 0, 0);
    pthread_t tid_producers[NUM_PRODUCER];
    pthread_t tid_consumers[NUM_CONSUMER];
    int ids_producers[NUM_PRODUCER];
    int ids_consumers[NUM_CONSUMER];

    for (int i = 0; i < NUM_CONSUMER; ++i) {
        ids_consumers[i] = i ;
        pthread_create(tid_consumers + i, NULL, consumer, static_cast<void*>(ids_consumers + i));
    }

    for (int i = 0; i < NUM_PRODUCER; ++i) {
        ids_producers[i] = i ;
        pthread_create(tid_producers + i, NULL, producer, static_cast<void*>(ids_producers + i));
    }

    for (int i = 0; i < NUM_CONSUMER; ++i) {
        pthread_join(tid_consumers[i],NULL);
    }

    for (int i = 0; i < NUM_PRODUCER; ++i) {
        pthread_join(tid_producers[i], NULL);
    }
    pthread_exit(nullptr);
}
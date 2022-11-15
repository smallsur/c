#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER 3
#define NUM_APPLE_PRODUCED_BY_FATHER 10
#define NUM_ORANGE_PRODUCED_BY_MOTHER 10
pthread_mutex_t lock_stream = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_plate = PTHREAD_MUTEX_INITIALIZER;
sem_t empty, full_son, full_daughter;

int plate_orange[3] = {0, 0, 0};
int plate_apple[3] = {0, 0, 0};

int index[2] = {0, 0};


void* father(void* args){
    int i = 0;
    while (i < NUM_APPLE_PRODUCED_BY_FATHER){
        sem_wait(&empty);
        //
        pthread_mutex_lock(&lock_plate);
        //
        pthread_mutex_lock(&lock_stream);
        std::cout<< "father produce a apple id: "<< index[1]<< std::endl;
        pthread_mutex_unlock(&lock_stream);

        plate_apple[index[1]] = index[1];
        index[1] = (index[1] + 1) % BUFFER;
        i++;

        pthread_mutex_unlock(&lock_plate);

        sem_post(&full_daughter);
    }
    pthread_exit(nullptr);
}

void* mother(void* args){
    int i = 0;
    while (i < NUM_ORANGE_PRODUCED_BY_MOTHER){
        sem_wait(&empty);

        pthread_mutex_lock(&lock_plate);
        //
        pthread_mutex_lock(&lock_stream);
        std::cout<< "mother produce a orange id: "<< index[0]<< std::endl;
        pthread_mutex_unlock(&lock_stream);

        plate_orange[index[0]] = index[0];
        index[0] = (index[0] + 1) % BUFFER;
        i++;

        pthread_mutex_unlock(&lock_plate);

        sem_post(&full_son);
    }
    pthread_exit(nullptr);
}

void* son(void* args){
    int i = 0;
    while (i < NUM_ORANGE_PRODUCED_BY_MOTHER){
        sem_wait(&full_son);

        pthread_mutex_lock(&lock_plate);

        index[0] = (index[0] + BUFFER - 1) % BUFFER;
        i++;

        pthread_mutex_lock(&lock_stream);

        std::cout<< "son consume a orange id: "<< index[0]<< std::endl;
        pthread_mutex_unlock(&lock_stream);

        pthread_mutex_unlock(&lock_plate);

        sem_post(&empty);
    }
    pthread_exit(nullptr);
}

void* daughter(void* args){
    int i = 0;
    while (i < NUM_APPLE_PRODUCED_BY_FATHER){
        sem_wait(&full_daughter);

        pthread_mutex_lock(&lock_plate);

        index[1] = (index[1] + BUFFER - 1) % BUFFER;
        i++;

        pthread_mutex_lock(&lock_stream);

        std::cout<< "daughter consume a apple id: "<< index[1]<< std::endl;
        pthread_mutex_unlock(&lock_stream);


        pthread_mutex_unlock(&lock_plate);

        sem_post(&empty);
    }
    pthread_exit(nullptr);
}

int main(){
    sem_init(&empty, 0, BUFFER);
    sem_init(&full_son, 0, 0);
    sem_init(&full_daughter, 0, 0);

    pthread_t tid_father;
    pthread_t tid_mother;
    pthread_t tid_son;
    pthread_t tid_daughter;

    pthread_create(&tid_daughter, NULL, daughter, NULL);
    pthread_create(&tid_son, NULL, son, NULL);
    pthread_create(&tid_mother, NULL, mother, NULL);
    pthread_create(&tid_father, NULL, father, NULL);

    pthread_join(tid_daughter, NULL);
    pthread_join(tid_father, NULL);
    pthread_join(tid_son, NULL);
    pthread_join(tid_mother, NULL);

    pthread_exit(nullptr);
}
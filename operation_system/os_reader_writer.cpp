#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_READER 10
#define NUM_WRITER 5

#define MAX_READER_COUNT 10

#define NUM_WRITER_WRITE 5
#define NUM_READER_READ 10

pthread_mutex_t lock_writer_reader = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_stream = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock_reader = PTHREAD_MUTEX_INITIALIZER;

std::string buffer = "";
int readCount = 0;

void* reader(void* args){
    int *id = static_cast<int *>(args);
    int i = 0;
    while(i < NUM_READER_READ) {
        pthread_mutex_lock(&lock_reader);
        if (readCount == 0) {
            pthread_mutex_lock(&lock_writer_reader);
        }
        readCount++;
        pthread_mutex_unlock(&lock_reader);

        pthread_mutex_lock(&lock_stream);
        std::cout << "reader " << *id << "read str :\" " << buffer << " \"" << std::endl;
        i++;
        pthread_mutex_unlock(&lock_stream);

        pthread_mutex_lock(&lock_reader);
        readCount--;
        if (readCount == 0) {
            pthread_mutex_unlock(&lock_writer_reader);
        }
        pthread_mutex_unlock(&lock_reader);
    }
    pthread_exit(nullptr);
}


void* writer(void* args){
    int *id = static_cast<int *>(args);
    int i = 0;
    while (i < NUM_WRITER_WRITE) {
        pthread_mutex_lock(&lock_writer_reader);

        pthread_mutex_lock(&lock_stream);
        std::cout << "writer " << *id << " write something" << std::endl;
        buffer.append("zaw");
        i++;
        pthread_mutex_unlock(&lock_stream);

        pthread_mutex_unlock(&lock_writer_reader);
    }
    pthread_exit(nullptr);
}

int main(){
    pthread_t tid_reader[NUM_READER];
    pthread_t  tid_writer[NUM_WRITER];

    int index_r[NUM_READER];
    int index_w[NUM_WRITER];

    for (int i = 0; i < NUM_WRITER; ++i) {
        index_w[i] = i;
        pthread_create(tid_writer+i, NULL, writer, static_cast<void *>(index_w+i));
    }
    for (int i = 0; i < NUM_READER; ++i) {
        index_r[i] = i;
        pthread_create(tid_reader+i, NULL, reader, static_cast<void *>(index_r+i));
    }

    for (int i = 0; i < NUM_READER; ++i) {
        pthread_join(tid_reader[i], NULL);
    }
    for (int i = 0; i < NUM_WRITER; ++i) {
        pthread_join(tid_writer[i], NULL);
    }
    pthread_exit(nullptr);
}
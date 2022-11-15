#include <iostream>

#include <thread>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5
#define NUM_ARGS 5

void* say_hello(void* args)
{
    int *i = static_cast<int*>(args);
    int n = *(i++);
    for (int j = 0; j < n ; ++j) {
        cout<< *(i + j)<< ' ';
     }
    cout<< endl;
    pthread_exit(0);
}

int main(){
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attrs[NUM_THREADS];
    for (pthread_attr_t &attr : attrs) {
        pthread_attr_init(&attr);
    }
    int indexes[NUM_ARGS+1];
    indexes[0] = NUM_ARGS;
    for (int i = 1; i < NUM_ARGS+1; ++i) {
        indexes[i] = i;
    }
    int rc;
    for(unsigned long & thread : threads){
        rc = pthread_create(&thread, nullptr,
                            say_hello, reinterpret_cast<void *>(indexes));
        if (rc){
            cout << "Error:无法创建线程," << rc << endl;
            exit(-1);
        }
    }
    for (unsigned long & thread : threads) {
        pthread_join(thread, NULL);
    }
}
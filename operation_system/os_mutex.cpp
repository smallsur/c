#include <iostream>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2
using namespace std;
int ticketAmount = 2;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void* ticketAgent(void* args){
    pthread_mutex_lock(&lock);
    int t = ticketAmount;
    if(t > 0){
        cout<< "one ticket sold!\n"<<endl;
        t--;
    } else{
        cout<< "ticket sold out!\n"<<endl;
    }
    ticketAmount = t;
    pthread_mutex_unlock(&lock);
    pthread_exit(nullptr);
}

int main(){
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(tids + i, NULL, ticketAgent, NULL);
    }
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(tids[i], NULL);
    }
    cout<< ticketAmount<< endl;
}
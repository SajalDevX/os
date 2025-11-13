#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full;       // Counting semaphores
pthread_mutex_t mutex;   // For mutual exclusion

void *producer(void *arg) {
    int item = 1;
    while(1) {
        sem_wait(&empty);            // Wait for empty slot
        pthread_mutex_lock(&mutex);  // Enter critical section

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % SIZE;
        item++;

        pthread_mutex_unlock(&mutex); // Leave critical section
        sem_post(&full);              // Increase filled slot
        sleep(1);
    }
}

void *consumer(void *arg) {
    while(1) {
        sem_wait(&full);             // Wait for filled slot
        pthread_mutex_lock(&mutex);  // Enter critical section

        int item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex); // Leave critical section
        sem_post(&empty);             // Increase empty slot
        sleep(2);
    }
}

int main() {
    pthread_t prod, cons;

    sem_init(&empty, 0, SIZE); // All slots empty initially
    sem_init(&full, 0, 0);     // No full slots initially
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

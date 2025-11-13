#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5  // number of philosophers

pthread_mutex_t chopstick[N];

void *philosopher(void *num) {
    int id = *(int *)num;
    int left = id;
    int right = (id + 1) % N;

    while(1) {
        printf("Philosopher %d is thinking 💭\n", id+1);
        sleep(1);

        pthread_mutex_lock(&chopstick[left]);
        pthread_mutex_lock(&chopstick[right]);

        printf("Philosopher %d is eating 🍝\n", id+1);
        sleep(2);

        pthread_mutex_unlock(&chopstick[right]);
        pthread_mutex_unlock(&chopstick[left]);
    }
}

int main() {
    pthread_t philo[N];
    int id[N];

    for(int i=0;i<N;i++)
        pthread_mutex_init(&chopstick[i], NULL);

    for(int i=0;i<N;i++) {
        id[i] = i;
        pthread_create(&philo[i], NULL, philosopher, &id[i]);
    }

    for(int i=0;i<N;i++)
        pthread_join(philo[i], NULL);

    for(int i=0;i<N;i++)
        pthread_mutex_destroy(&chopstick[i]);

    return 0;
}

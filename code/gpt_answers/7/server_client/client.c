#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 1234

int main() {
    int shmid;
    char *shared_msg;

    // Locate shared memory segment created by server
    shmid = shmget(SHM_KEY, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach
    shared_msg = (char*) shmat(shmid, NULL, 0);
    if (shared_msg == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    // Read message
    printf("\nMessage read from shared memory:\n%s\n", shared_msg);

    // Detach
    shmdt(shared_msg);

    // Optional: remove shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

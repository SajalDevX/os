#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_KEY 1234

int main() {
    int shmid;
    char *shared_msg;

    // Create shared memory segment of 1024 bytes
    shmid = shmget(SHM_KEY, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory
    shared_msg = (char*) shmat(shmid, NULL, 0);
    if (shared_msg == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    // Write message
    printf("Enter message to write in shared memory:\n");
    fgets(shared_msg, 1024, stdin);

    printf("Message written to shared memory.\n");
    printf("Waiting before detaching...\n");
    sleep(5);

    // Detach
    shmdt(shared_msg);
    return 0;
}

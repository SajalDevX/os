#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int arr[5], i;
    printf("Enter 5 integers: ");
    for (i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process: run child.c
        execl("./child", "child", NULL);
    } 
    else if (pid > 0) {
        // Parent process: sort numbers
        int j, temp;
        for (i = 0; i < 5; i++)
            for (j = i + 1; j < 5; j++)
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }

        printf("\nParent (PID %d) sorted array: ", getpid());
        for (i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("\n");

        wait(NULL); // Wait for child to finish
        printf("Child completed. Parent exiting.\n");
    } 
    else {
        printf("Fork failed!\n");
    }

    return 0;
}

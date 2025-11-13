#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sort(int a[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) {
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
}

int main() {
    int n, a[10];
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    sort(a,n);

    pid_t pid = fork();
    if(pid==0) { // child
        char *args[15];
        args[0] = "./child"; // program to exec
        for(int i=0;i<n;i++){
            char *num = malloc(10);
            sprintf(num, "%d", a[i]);
            args[i+1] = num;
        }
        args[n+1] = NULL;
        execve(args[0], args, NULL);
        perror("execve failed");
    } 
    else {
        wait(NULL);
        printf("\nParent: child finished.\n");
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int arr[5] = {9, 3, 5, 1, 7}; // Child sorts its own numbers
    int i, j, temp;

    printf("\nChild (PID %d) sorting its own array...\n", getpid());

    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++)
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    printf("Child sorted array: ");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Uncomment below to show orphan (child runs after parent exits)
    // sleep(5);

    return 0;
}

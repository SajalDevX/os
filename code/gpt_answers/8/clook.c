#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 9;
    int req[] = {27, 129, 110, 186, 147, 41, 10, 64, 120};
    int head = 63;
    int total = 0;
    int i, j, index = 0;

    // Sort requests
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(req[j] > req[j + 1]) {
                int t = req[j];
                req[j] = req[j + 1];
                req[j + 1] = t;
            }

    // Find head position index
    for(i = 0; i < n; i++)
        if(head < req[i]) {
            index = i;
            break;
        }

    printf("Initial Head Position: %d\n", head);
    printf("Request Queue: 27 129 110 186 147 41 10 64 120\n\n");
    printf("Sequence of Head Movement:\n");

    // Move upward first
    for(i = index; i < n; i++) {
        printf("%d ", req[i]);
        total += abs(req[i] - head);
        head = req[i];
    }

    // Jump to lowest request (circular move)
    total += abs(req[n - 1] - req[0]);
    head = req[0];
    printf(" | jump | ");

    for(i = 0; i < index; i++) {
        printf("%d ", req[i]);
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("\n\nTotal Head Movement = %d Cylinders\n", total);
    printf("Average Head Movement = %.2f\n", (float)total / n);

    return 0;
}

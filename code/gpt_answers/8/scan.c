#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 9;
    int req[] = {27, 129, 110, 186, 147, 41, 10, 64, 120};
    int head = 63, total = 0, direction = 1; // 1 = up (away from spindle)
    int size = 200;
    int temp[11], index = 0;

    // Add head and boundaries
    for(int i = 0; i < n; i++) temp[i] = req[i];
    temp[n] = head;
    temp[n+1] = size - 1;
    n += 2;

    // Sort all
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(temp[j] > temp[j+1]) {
                int t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = t;
            }

    // Find head index
    for(int i = 0; i < n; i++)
        if(temp[i] == head) { index = i; break; }

    printf("Initial Head Position: %d\n", head);
    printf("Request Queue: 27 129 110 186 147 41 10 64 120\n\n");
    printf("Sequence of Head Movement:\n");

    int order[20], k = 0;

    // Move toward higher cylinders first
    if(direction == 1) {
        for(int i = index; i < n; i++)
            order[k++] = temp[i];
        for(int i = index - 1; i >= 0; i--)
            order[k++] = temp[i];
    } else { // move down first
        for(int i = index; i >= 0; i--)
            order[k++] = temp[i];
        for(int i = index + 1; i < n; i++)
            order[k++] = temp[i];
    }

    for(int i = 0; i < k - 1; i++)
        total += abs(order[i+1] - order[i]);

    for(int i = 0; i < k; i++)
        printf("%d ", order[i]);
    printf("\n\nTotal Head Movement = %d Cylinders\n", total);
    printf("Average Head Movement = %.2f\n", (float)total / (k - 1));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 9;
    int req[] = {27, 129, 110, 186, 147, 41, 10, 64, 120};
    int head = 63, total = 0, visited[9] = {0};

    printf("Initial Head Position: %d\n", head);
    printf("Request Queue: ");
    for(int i=0;i<n;i++) printf("%d ", req[i]);
    printf("\n\nSequence of Head Movement:\n");

    for(int i=0;i<n;i++) {
        int min = 9999, pos = -1;
        for(int j=0;j<n;j++) {
            if(!visited[j]) {
                int diff = abs(head - req[j]);
                if(diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }
        visited[pos] = 1;
        total += abs(head - req[pos]);
        head = req[pos];
        printf("%d ", head);
    }

    printf("\n\nTotal Head Movement = %d Cylinders\n", total);
    printf("Average Head Movement = %.2f\n", (float)total/n);
    return 0;
}

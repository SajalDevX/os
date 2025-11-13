#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[10], at[10], bt[10], wt[10], tat[10], ct[10];
    for (int i=0; i<n; i++) {
        pid[i] = i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int done[10] = {0}, completed = 0, time = 0;
    float totalWT = 0;

    while (completed < n) {
        int idx = -1, minBT = 9999;
        for (int i=0; i<n; i++) {
            if (!done[i] && at[i] <= time && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
            continue;
        }
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        totalWT += wt[idx];
        done[idx] = 1;
        completed++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\tCT\n");
    for (int i=0; i<n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i], ct[i]);

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    return 0;
}

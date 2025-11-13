#include <stdio.h>

int main() {
    int n, tq = 2;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[10], at[10], bt[10], rt[10], wt[10], tat[10], ct[10];
    for (int i=0; i<n; i++) {
        pid[i] = i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        wt[i] = 0;
    }

    int time = 0, done = 0;
    while (done < n) {
        int executed = 0;
        for (int i=0; i<n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                executed = 1;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    done++;
                }
            }
        }
        if (!executed) time++; // CPU idle if no process has arrived
    }

    float totalWT = 0;
    printf("\nProcess\tAT\tBT\tWT\tCT\n");
    for (int i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        totalWT += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], ct[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT/n);
    return 0;
}

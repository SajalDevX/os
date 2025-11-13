#include <stdio.h>

int main() {
    int pages[20] = {1,2,1,5,1,5,4,1,2,2,1,4,3,4,5,2,1};
    int n = 17, frames = 4;
    int f[10], faults = 0, flag, count = 0;

    // ---------- FCFS ----------
    printf("\n--- FCFS Page Replacement ---\n");
    for (int i = 0; i < frames; i++) f[i] = -1;
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < frames; j++)
            if (f[j] == pages[i]) flag = 1;
        if (!flag) {
            f[count % frames] = pages[i];
            count++;
            faults++;
        }
        printf("After page %2d: ", pages[i]);
        for (int j = 0; j < frames; j++)
            if (f[j] != -1) printf("%d ", f[j]);
            else printf("- ");
        printf("\n");
    }
    printf("Total Page Faults (FCFS): %d\n", faults);

    // ---------- OPTIMAL ----------
    printf("\n--- OPTIMAL Page Replacement ---\n");
    for (int i = 0; i < frames; i++) f[i] = -1;
    faults = 0;

    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < frames; j++)
            if (f[j] == pages[i]) flag = 1;

        if (!flag) {
            int pos = -1, farthest = i + 1, idx = -1;
            for (int j = 0; j < frames; j++) {
                if (f[j] == -1) { pos = j; break; }
                int k;
                for (k = i + 1; k < n; k++)
                    if (f[j] == pages[k]) break;
                if (k > farthest) {
                    farthest = k;
                    pos = j;
                }
                if (k == n) { pos = j; break; }
            }
            if (pos == -1) pos = 0;
            f[pos] = pages[i];
            faults++;
        }

        printf("After page %2d: ", pages[i]);
        for (int j = 0; j < frames; j++)
            if (f[j] != -1) printf("%d ", f[j]);
            else printf("- ");
        printf("\n");
    }
    printf("Total Page Faults (Optimal): %d\n", faults);

    return 0;
}

#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++)
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    return pos;
}

int main() {
    int pages[20] = {1,2,1,5,1,5,4,1,2,2,1,4,3,4,5,2,1};
    int n = 17, frames = 3;
    int f[3], count = 0, faults = 0, flag, time[3];
    
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

    // ---------- LRU ----------
    printf("\n--- LRU Page Replacement ---\n");
    for (int i = 0; i < frames; i++) f[i] = -1;
    faults = 0;
    int counter = 0;

    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < frames; j++) {
            if (f[j] == pages[i]) {
                flag = 1;
                time[j] = ++counter;
            }
        }
        if (!flag) {
            int pos = -1;
            for (int j = 0; j < frames; j++)
                if (f[j] == -1) { pos = j; break; }

            if (pos == -1) pos = findLRU(time, frames);
            f[pos] = pages[i];
            time[pos] = ++counter;
            faults++;
        }
        printf("After page %2d: ", pages[i]);
        for (int j = 0; j < frames; j++)
            if (f[j] != -1) printf("%d ", f[j]);
            else printf("- ");
        printf("\n");
    }
    printf("Total Page Faults (LRU): %d\n", faults);
    return 0;
}

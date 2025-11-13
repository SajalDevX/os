#include <stdio.h>

int main() {
    int n = 5, m = 4;  // 5 processes, 4 resources (A, B, C, D)

    int alloc[5][4] = {
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4}
    };

    int max[5][4] = {
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6}
    };

    int avail[4] = {1, 5, 2, 0};

    int f[5] = {0}, ans[5], ind = 0;
    int need[5][4];

    // Calculate Need matrix = Max - Allocation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int safe = 1;
    for (int i = 0; i < n; i++)
        if (f[i] == 0) safe = 0;

    if (safe) {
        printf("\nSystem is in a Safe State.\nSafe Sequence is: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", ans[i]);
        printf("\n");
    } else
        printf("\nSystem is NOT in a Safe State.\n");

    return 0;
}

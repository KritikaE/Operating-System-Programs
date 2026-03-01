#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10], finish[10] = {0};
    int safe[10], count = 0;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter number of resources:\n");
    scanf("%d", &m);

    printf("Enter Allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    // Need = Max - Allocation
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety Algorithm
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                for(j = 0; j < m; j++)
                    if(need[i][j] > work[j])
                        break;

                if(j == m) {
                    for(k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
            break;
    }

    if(count == n) {
        printf("System is in SAFE state\nSafe sequence: ");
        for(i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    } else {
        printf("System is NOT in safe state");
    }

    return 0;
}

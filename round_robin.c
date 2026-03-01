#include <stdio.h>

int main() {
    int n, i, time = 0, tq;
    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int completed = 0;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter Time Quantum:\n");
    scanf("%d", &tq);

    for(i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d:\n", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time
    }

    while(completed < n) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }
    }

    // TAT & WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

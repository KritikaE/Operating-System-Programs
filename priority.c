#include <stdio.h>

int main() {
    int n;
    int at[10], bt[10], pr[10], ct[10], tat[10], wt[10];
    int done[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter AT BT Priority for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    int time = 0;

    for(int count = 0; count < n; count++) {
        int idx = -1, best_pr = 9999;

        // find highest priority (smallest number) among arrived
        for(int i = 0; i < n; i++) {
            if(done[i] == 0 && at[i] <= time && pr[i] < best_pr) {
                best_pr = pr[i];
                idx = i;
            }
        }

        // if no process available → move time forward
        if(idx == -1) {
            time++;
            count--;   // retry same round
        }
        else {
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
        }
    }

    // calculate TAT and WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

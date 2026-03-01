#include <stdio.h>

int main() {
    int n, i, j, temp;
    int at[10], bt[10], pr[10], ct[10], tat[10], wt[10];

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT BT Priority for P%d:\n", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    // First process
    ct[0] = at[0] + bt[0];

    // Sort by priority (from second process)
    for(i = 1; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
            }
        }
    }

    // Completion time
    for(i = 1; i < n; i++)
        ct[i] = ct[i-1] + bt[i];

    // TAT & WT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

//NON PREMPTIVE
#include<stdio.h>

void main(){
    int n;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    int done[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int time = 0;

    for(int count = 0; count < n; count++){
        int min = 9999, idx = -1;

        // find shortest available process
        for(int i=0; i<n; i++){
            if(done[i]==0 && at[i] <= time && bt[i] < min){
                min = bt[i];
                idx = i;
            }
        }

        if(idx == -1){
            time++;      // no process yet → wait
            count--;     // retry same iteration
        }
        else{
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
        }
    }

    for(int i=0; i<n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}

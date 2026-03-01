#include<stdio.h>

void main(){
    int n;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    
    printf("Enter the number of process\n");
    scanf("%d\n",&n);
    
    for(int i = 0; i<n; i++){
        printf("Enter the AT and BT for %d",i);
        scanf("%d %d",&at[i], &bt[i]);
        //scanf("%d", &bt[i]);
    }
    
    ct[0]=at[0]+bt[0];
    
    for(int i=1; i<n; i++){
        if(at[i]>ct[i-0])
            ct[i]=at[i]+bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
    }
    
    for(int i = 0; i<n; i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    
    
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i =0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

}

/* o/p
Enter number of processes: 3
Enter AT and BT for P1: 0 5
Enter AT and BT for P2: 1 3
Enter AT and BT for P3: 2 4 
P   AT  BT  CT  TAT WT
P1  0   5   5   5   0
P2  1   3   8   7   4
P3  2   4   12  10  6*/

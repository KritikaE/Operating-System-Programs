//NON PRE-EMPTIVE
#include<stdio.h>

void main(){
    int n;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    
    printf("Enter the number of process\n");
    scanf("%d\n",&n);
    
    for(int i = 0; i<n; i++){
        printf("Enter the AT and BT for %d",i);
        scanf("%d %d",&at[i], &bt[i]);

    }
    
    ct[0]=at[0]+bt[0];
    
    int temp; 
    //sort bt in ascending order
    for(int i =1; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            temp = at[i]; at[i] = at[j]; at[j] = temp;
        }
    }
    
    for(int i=1; i<n; i++){
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

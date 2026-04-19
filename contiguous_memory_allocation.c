#include <stdio.h>

int main() {
    int b[10], p[10], temp[10];
    int n, m, i, j, choice;

    printf("Blocks: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d",&b[i]);

    printf("Processes: ");
    scanf("%d", &m);
    for(i=0;i<m;i++) scanf("%d",&p[i]);

    printf("\n1.First Fit  2.Best Fit  3.Worst Fit\n");
    scanf("%d",&choice);

    // copy original blocks (important!)
    for(i=0;i<n;i++) temp[i] = b[i];

    printf("\nP\tB\n");

    for(i=0;i<m;i++) {
        int index = -1;

        for(j=0;j<n;j++) {
            if(temp[j] >= p[i]) {

                if(choice == 1) {          // FIRST FIT
                    index = j;
                    break;
                }

                else if(choice == 2) {     // BEST FIT
                    if(index==-1 || temp[j] < temp[index])
                        index = j;
                }

                else if(choice == 3) {     // WORST FIT
                    if(index==-1 || temp[j] > temp[index])
                        index = j;
                }
            }
        }

        if(index != -1) {
            printf("%d\t%d\n", i+1, index+1);
            temp[index] -= p[i];
        } else {
            printf("%d\tNA\n", i+1);
        }
    }

    return 0;
}

/* o/p:
Blocks: 3
100 500 200

Processes: 3
120 50 200

1.First Fit  2.Best Fit  3.Worst Fit
1

P       B
1       2
2       1
3       NA

2
P       B
1       3
2       1
3       2

3
P       B
1       2
2       2
3       2
*/

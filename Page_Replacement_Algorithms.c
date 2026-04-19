#include <stdio.h>

int main() {
    int pages[20], frames[10];
    int n, f, i, j, k, choice;
    int faults = 0, found;

    printf("Number of pages: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) scanf("%d", &pages[i]);

    printf("Number of frames: ");
    scanf("%d", &f);

    printf("1.FCFS  2.LRU  3.Optimal\n");
    scanf("%d", &choice);

    // initialize frames
    for(i=0;i<f;i++) frames[i] = -1;

    printf("\nPage\tFrames\n");

    for(i=0;i<n;i++) {
        found = 0;

        // check hit
        for(j=0;j<f;j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            faults++;

            int pos = 0;

            // FCFS
            if(choice == 1) {
                pos = i % f;
            }

            // LRU
            else if(choice == 2) {
                int least = 999;
                for(j=0;j<f;j++) {
                    int last = -1;
                    for(k=i-1;k>=0;k--) {
                        if(frames[j] == pages[k]) {
                            last = k;
                            break;
                        }
                    }
                    if(last < least) {
                        least = last;
                        pos = j;
                    }
                }
            }

            // OPTIMAL
            else if(choice == 3) {
                int farthest = -1;
                for(j=0;j<f;j++) {
                    int next = 999;
                    for(k=i+1;k<n;k++) {
                        if(frames[j] == pages[k]) {
                            next = k;
                            break;
                        }
                    }
                    if(next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
        }

        // print table row
        printf("%d\t", pages[i]);
        for(j=0;j<f;j++) {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if(found)
            printf("(Hit)");
        else
            printf("(Fault)");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}

/* o/p:

Number of pages: 7
1 2 3 2 4 1 5
Number of frames: 3
  
1. FCFS

Page    Frames
1       1 - -   (Fault)
2       1 2 -   (Fault)
3       1 2 3   (Fault)
2       1 2 3   (Hit)
4       4 2 3   (Fault)
1       4 1 3   (Fault)
5       4 1 5   (Fault)

Total Page Faults = 6

2. LRU
 
Page   Frames
1      1 - -
2      1 2 -
3      1 2 3
2      1 2 3   (hit)
4      4 2 3   (1 least used)
1      4 2 1   (3 least used)
5      5 2 1   (4 least used)

Total Page Faults = 6

3. OPTIMAL

Page   Frames
1      1 - -
2      1 2 -
3      1 2 3
2      1 2 3   (hit)
4      1 2 4   (3 not used in future)
1      1 2 4   (hit)
5      5 2 4   (1 not used in future)

Total Page Faults = 5 */

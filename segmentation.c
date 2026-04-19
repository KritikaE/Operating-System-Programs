#include <stdio.h>

int main() {
    int n, base[10], limit[10];
    int seg, off, pa;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    printf("Enter base and limit:\n");
    for(int i=0; i<n; i++) {
        scanf("%d %d", &base[i], &limit[i]);
    }

    printf("Enter segment number and offset: ");
    scanf("%d %d", &seg, &off);

    if(seg >= n || off >= limit[seg]) {
        printf("Segmentation Fault");
    } else {
        pa = base[seg] + off;
        printf("Physical Address = %d", pa);
    }

    return 0;
}

/* o/p:
Enter number of segments: 3
Enter base and limit:
100 50
200 100
400 150

Enter segment number and offset: 1 20

Physical Address = 220
  */

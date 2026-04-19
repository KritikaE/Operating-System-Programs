#include <stdio.h>

int main() {
    int n, pt[10];        // number of pages + page table
    int size;             // page size
    int la;               // logical address
    int p, off;           // page number, offset
    int frame, pa;        // frame number, physical address

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page table (frame numbers):\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &pt[i]);
    }

    printf("Enter page size: ");
    scanf("%d", &size);

    printf("Enter logical address: ");
    scanf("%d", &la);

    // Step 1: break logical address
    p = la / size;
    off = la % size;

    // Step 2: check valid page
    if(p >= n) {
        printf("Invalid page");
    } else {
        // Step 3: get frame
        frame = pt[p];

        // Step 4: calculate physical address
        pa = frame * size + off;

        printf("Page = %d\n", p);
        printf("Offset = %d\n", off);
        printf("Frame = %d\n", frame);
        printf("Physical Address = %d\n", pa);
    }

    return 0;
}

/* o/p:
Enter number of pages: 3
Enter page table (frame numbers):
5 2 7
Enter page size: 100
Enter logical address: 220

Page = 2
Offset = 20
Frame = 7
Physical Address = 720
    */

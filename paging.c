#include <stdio.h>

int main() {
    int pages, frames, i;
    int page_table[10];
    int page, offset, physical_addr;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter frame number for each page:\n");
    for(i = 0; i < pages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &page_table[i]);
    }

    printf("\nEnter page number: ");
    scanf("%d", &page);

    printf("Enter offset: ");
    scanf("%d", &offset);

    physical_addr = page_table[page] * 100 + offset;

    printf("Physical Address = %d\n", physical_addr);

    return 0;
}

/* o/p:
Enter number of pages: 3
Page 0 -> Frame: 5
Page 1 -> Frame: 2
Page 2 -> Frame: 7

Enter page number: 1
Enter offset: 20

Physical Address = 220*/

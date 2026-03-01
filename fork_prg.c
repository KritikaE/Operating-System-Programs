#include<stdio.h>
#include<unistd.h>

void main(){
    fork();
    
    printf("Child process");
    printf("Parent process");
    printf("\n");
}

/* o/p:
Child processParent process
Child processParent process
*/

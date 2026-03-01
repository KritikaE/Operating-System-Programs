#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void main(){
    int pid = fork();
    
    if(pid==0){
        printf("Child process\n");
        
    }
    else{
        wait(NULL);
        printf("Parent process");
        printf("\n");
    }
}

/* o/p
Child process
Parent process
  */

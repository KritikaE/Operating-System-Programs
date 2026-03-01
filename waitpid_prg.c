#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void main(){
    int pid = fork();
    
    if(pid==0){
        printf("Child process\n");
        
    }
    else{
        waitpid(pid,NULL,0);
        printf("Parent process");
        printf("\n");
    }
}

/* o/p
Child process
Parent process
  */

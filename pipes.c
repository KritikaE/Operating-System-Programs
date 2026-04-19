#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello from parent";
    char read_msg[50];

    pipe(fd);   // create pipe

    if(fork() == 0) {
        // Child process
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
    } else {
        // Parent process
        write(fd[1], write_msg, strlen(write_msg) + 1);
    }

    return 0;
}

/* o/p: 
  Child received: Hello from parent*/

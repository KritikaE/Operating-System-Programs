#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("myfifo", 0666);

    if (fork() == 0) {
        // Child → read
        int fd = open("myfifo", O_RDONLY);
        char msg[50];
        read(fd, msg, sizeof(msg));
        printf("Received: %s\n", msg);
        close(fd);
    } else {
        // Parent → write
        int fd = open("myfifo", O_WRONLY);
        write(fd, "Hello through FIFO", 20);
        close(fd);
    }
}

/* o/p:
Received: Hello through FIFO*/

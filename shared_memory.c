#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    int shmid = shmget(1234, 1024, 0666 | IPC_CREAT);

    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    if (fork() == 0) {
        sleep(1);

        char *data = shmat(shmid, NULL, 0);
        if (data == (void*) -1) {
            perror("shmat failed");
            return 1;
        }

        printf("Received: %s\n", data);
        shmdt(data);

    } else {
        char *data = shmat(shmid, NULL, 0);
        if (data == (void*) -1) {
            perror("shmat failed");
            return 1;
        }

        strcpy(data, "Hello via Shared Memory");
        printf("Written to memory\n");

        shmdt(data);

        // Cleanup
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

/*o/p:
Written to memory
Received: Hello via Shared Memory*/

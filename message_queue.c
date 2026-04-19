#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    struct msg message;
    int msgid;

    msgid = msgget(1234, 0666 | IPC_CREAT);

    if(fork() == 0) {
        // Child - Receiver
        msgrcv(msgid, &message, sizeof(message.text), 1, 0);
        printf("Received: %s\n", message.text);
    } else {
        // Parent - Sender
        message.type = 1;
        strcpy(message.text, "Hello via Message Queue");
        msgsnd(msgid, &message, sizeof(message.text), 0);
    }

    return 0;
}

/* o/p:
Received: Hello via Message Queue*/

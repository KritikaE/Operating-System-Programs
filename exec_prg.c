#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec\n");
    fflush(stdout);
    execlp("ls", "ls", NULL);
    printf("After exec\n"); // never executes
    return 0;
}

/*o/p
  Before exec
in.txt
out.txt
process.txt
sol
sol.c
solution_source.txt
  */

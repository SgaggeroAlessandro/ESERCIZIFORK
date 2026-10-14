#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void) {

    for (int i = 0; i < 3; i++) {
        pid_t r = fork();


        if (r == -1) {
            perror("error");
            exit(1);
        }

        if (r == 0) {
            pid_t pid = getpid();
            printf("PID processo figlio:  %d \n", pid);
            fflush(stdout);
            sleep(2);
            exit(0);
        }
    }

    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }
    printf("Tutti i processi figlio sono terminati\n");
    return 0;
}

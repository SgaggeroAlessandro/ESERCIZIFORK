#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
   pid_t r = fork();

    if (r == -1) {
        perror("error");
        exit(1);
    }
    if (r == 0) {//padre di r2, figlio di r
        pid_t r2 = fork();

        if (r2 == -1) {
            perror("error");
            exit(1);
        }
        if (r2 == 0) {
            pid_t pidr2 = getpid();
            printf("Io sono il nipote e il mio PID è: %d \n", pidr2);
            fflush(stdout);
        }else{
            wait(NULL);
            pid_t pidr = getpid();
            printf("Io sono il padre e il mio PID è: %d \n", pidr);
            fflush(stdout);
        }
    }else { //nonno di r2, padre di r
        wait(NULL);
        pid_t pid = getpid();
        printf("Io sono il nonno e il mio PID è: %d \n", pid);
        fflush(stdout);
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void) {

    pid_t r = fork();


    if(r < 0){
        perror("error");
        return 1;
    }
    if (r == 0) { //figlio
        for(int j = 1; j < 6; j++){
            printf("%d \n", j);
            fflush(stdout);
            sleep(1);
        }
        exit(0);
    }else {//padre
        wait(NULL);
        for(int i = 6; i < 11; i++){
            printf("%d \n", i);
            fflush(stdout);
            sleep(1);
        }

    }
    return 0;
}
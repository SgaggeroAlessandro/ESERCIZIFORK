#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int numero) {
    if (numero <= 1) {
        return 0;
    }
    for (int i = 2; i <= numero/2; i++) {
        if (numero % i == 0) {
            return 0; //non primo
        }
    }
    return 1; //primo
}
int main(void) {
    pid_t r = fork();

    if (r == -1) {
        perror("error");
        exit(1);
    }
    int primo = 0;
    int numero = 0;
    if (r == 0) {

        printf("Scrivi quale numero vuoi inserire\n");
        fflush(stdout);
        scanf("%d",&numero);
        primo = isPrime(numero);
        int codice = 0;
        if (primo == 0) {
            if (numero % 2 == 0) {
                codice = 2;
            } else {
                codice = 3;
            }
        }else {
            codice = 1;
        }
        exit(codice);
    }else {
        int status;
        pid_t pid_child = wait(&status);
        int code = -1;
        if (WIFEXITED(status)) {
             code = WEXITSTATUS(status);
        }

        if (code == 1) {
            printf("Il numero scelto è primo \n");
            fflush(stdout);
        }else if (code == 2) {
            printf("Il numero scelto è pari e non primo \n");
            fflush(stdout);
        }else {
            printf("Il numero scelto è dispari e non primo \n");
            fflush(stdout);
        }

    }
    return 0;
}

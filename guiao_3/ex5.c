#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i;
    for(i=0; i<argc; i++){

        if(fork()==0){

            execlp(argv[i], argv[i], NULL);
            perror("argv[i]: ");
            _exit(0);
        }
    }

    for(i=0; i<argc; i++)
        wait(NULL);


}
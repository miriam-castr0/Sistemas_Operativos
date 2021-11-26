#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[]){
    pid_t pid;

    if((pid=fork())==0){
        printf("\n----Filho----\n");
        printf("Processo pai:%d\n", getppid());
        printf("Processo filho(proprio):%d\n", getpid());
        _exit(0);
    }
    else{
        printf("-----Pai-----\n");
        printf("Bash:%d\n", getppid());
        printf("Processo pai(proprio):%d\n", getpid());
        printf("Processo filho:%d\n", pid);
        
       sleep(1);
    }

    return 0;
}
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[]){
    int idf;
    int status;
    for(int i=0; i<10; i++){
        
        if(fork()==0){
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            _exit(i);
        }
        else{
            idf = wait(&status);
            printf("Processo que morreu: %d\n", idf);
            if(WIFEXITED(status)){
                int exitval= WEXITSTATUS(status);
                printf("Código de saída do filho: %d\n", exitval);
            }
            

        } 
    }
    
    

    return 0;
}
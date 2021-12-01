#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int pp[2];
    char str[] = "ola pai\n";
    char buf[sizeof(str)];
    if(pipe(pp)==-1){
        perror("error:" );
        return -1;
    }

    if(fork()==0){
        write(pp[1],str, sizeof(str)); //write in pipe
		close(pp[1]);
        _exit(0);

    }
    else{
        wait(NULL);
		read(pp[0], &buf, sizeof(buf)); //read pipe
        close(pp[0]); //!!!! always close descritors
        write(1, buf, sizeof(buf));
       
    }





    return 0;
}
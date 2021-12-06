#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){

    
	int pd[2];
    int pd1[2];
    int pd2[2];
	pipe(pd);
    pipe(pd1);
    pipe(pd2);

	if(fork()){
        if(fork()){
            if(fork()){
                close(pd[0]);
                dup2(pd[1], 1);
                execlp("grep", "grep", "-v", "ˆ#", "/etc/passwd", NULL);
                _exit(-1);

            }
            else{
                wait(NULL);
                dup2(pd[0], 0);
                dup2(pd[1], 1);
                execlp("cut", "cut", "-f7", "-d:", NULL );
            }

        }
        else{
            wait(NULL);
            wait(NULL);
            dup2(pd[0], 0);
            dup2(pd[1], 1);
            execlp("uniq", "uniq", NULL);
        

        }
       
    }
     else{
            wait(NULL);
            wait(NULL);
            wait(NULL);
            dup2(pd[0], 0);
            dup2(pd[1], 1);
            execlp("wc", "wc", "-l", NULL);
        

        }
	return 0;




}
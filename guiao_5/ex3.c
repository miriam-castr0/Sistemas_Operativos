#include <sys/types.h>
#include <unistd.h> //hamadas ao sistema: defs e decls essenciais 
#include <fcntl.h>  // O_RDONLY, O_WRONLY, O_CREAT, O_* 
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int pd[2];
	if(pipe(pd)==-1){
        perror("error:" );
        return -1;
    }
    char buf[1024];
    int n=0;

    if(fork()==0){

        close(pd[1]);
		dup2(pd[0], 0);
        while(read(0,&buf,sizeof(buf))> 0 && buf!=0){
			execlp("wc","wc",NULL);
	    }
		
        _exit(-1);
    }
    else{
        dup2(pd[1], 1);
        while((n=read(0, &buf, sizeof(buf)))>0 && buf[0]!='q')
            write(1, buf, n);
        close(pd[1]);
        wait(NULL);
    }




    return 0;
}
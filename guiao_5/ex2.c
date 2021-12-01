#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32

int main(){

    int pd[2];
    int n=0;
	if(pipe(pd)==-1){
        perror("error:" );
        return -1;
    }
    char str[] = "ola\n";
	int pid=fork();
	char buf[sizeof(str)];

	if(pid==0){
		
		close(pd[1]);
	    while((n=read(pd[0],&buf,sizeof(buf)))> 0){
			write(1,&buf,n);
	    }
		close(pd[0]);  
        _exit(0);

	}
	else{
		
		close(pd[0]);
		write(pd[1],str, sizeof(str));
        write(pd[1],str, sizeof(str));
        write(pd[1],str, sizeof(str));
		close(pd[1]);
        wait(NULL);
	}

	return 0;
}




 
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){

    
	int pd[2];
	pipe(pd);

	if (fork())
	{
		close(pd[0]);
		dup2(pd[1], 1);
		execlp("ls","ls","/etc",NULL);
        _exit(-1);
	} else {
		close(pd[1]);
		dup2(pd[0],0);
		execlp("wc","wc","-l",NULL);
        wait(NULL);
	}
	return 0;




}

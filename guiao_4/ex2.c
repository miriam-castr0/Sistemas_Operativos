#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char c;
	
	int fd2 = open("saida.txt", O_WRONLY | O_CREAT, 0666);
	dup2(fd2,1);
	
	int fd3 = open("erros.txt", O_RDWR | O_CREAT, 0666);
	dup2(fd3,2);
		
	int fd1 = open("passwords.txt", O_RDONLY);
	if(fd1==-1)
        {
                perror("error: ");
                return -1;
        }
    
    dup2(fd1,0);


	int pid;
	if((pid=fork())==0)
	{
		while((read(0, &c, sizeof(char)))>0)
		{
			write(1, &c, sizeof(char));
		}
		_exit(0);
	}
    else
	    wait(NULL);


	close(fd1);
	close(fd2);
	close(fd3);

    


    return 0;
}
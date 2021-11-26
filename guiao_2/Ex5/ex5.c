#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[]){
    int pid=0;
    
    for(int i=0;i<10;i++)
    {
        if(pid==0)//filho
        {
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid() );
            pid=fork();
        }
        else wait(NULL);//pai
    }
    

    return 0;
}
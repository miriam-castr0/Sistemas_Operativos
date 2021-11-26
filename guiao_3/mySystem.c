#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mySystem(char *arg)
{
    int i = 0;
    int words = 0, chars = 0, countL=1, countW=1;
    int status, exitval=-1, pid;
    char **args = (char **)malloc(1 * sizeof(char *));//allocates memory for 1 line
    
    args[0] = (char *)malloc(1 * sizeof(char));//allocates memory for 1 column

    for (i = 0; i < strlen(arg); i++)
    {
        if (arg[i] != ' ')
        {
            args[words]=(char *)realloc(args[words], countL * sizeof(char));
            args[words][chars] = arg[i];
            chars++;
            countL++;
        }
        else
        {
            countW++;
            args = (char **)realloc(args, countW * sizeof(char *));
            words++;
            chars = 0;
            countL=1;
        }
    }
    
    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("failed");
            _exit(-1);
        }
        else
            _exit(0);
    }
    else
    {
        if (pid == -1)
            perror("failed to create process");
        else
        {   
            wait(&status);
            free(args);
            if (WIFEXITED(status))
                exitval = WEXITSTATUS(status);
        }
    }

    return exitval;
}

int main(int argc, char *argv[])
{

    int value = mySystem("make ex6");

    return 0;
}
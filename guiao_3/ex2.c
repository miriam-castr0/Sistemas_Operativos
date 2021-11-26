#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

    if (fork() == 0)
    {
        execl("/bin/ls", "/bin/ls", "-l", NULL);
        perror("ls:");
        return -1;
    }
    else
        wait(NULL);

    return 0;
}
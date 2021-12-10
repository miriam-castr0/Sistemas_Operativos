#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    int pd1[2];
    int pd2[2];
    int pd3[2];

    pipe(pd3);

    if (fork())
    {
         pipe(pd2);
        if (fork())
        {
            pipe(pd1);
            if (fork())
            {
                dup2(pd1[1], 1);
                close(pd1[0]);
                close(pd1[1]);
                execlp("grep", "grep", "-v", "^#", "/etc/passwd", NULL);
                perror("error:");
                _exit(-1);
            }
            else
            {
                wait(NULL);
                dup2(pd1[0], 0);
                dup2(pd2[1], 1);
                close(pd1[0]);
                close(pd1[1]);
                close(pd2[0]);
                close(pd2[1]);
                execlp("cut", "cut", "-f7", "-d:", NULL);
                perror("error:");
                _exit(-1);
            }
        }
        else
        {
            wait(NULL);
            wait(NULL);
            dup2(pd2[0], 0);
            dup2(pd3[1], 1);
            close(pd2[0]);
            close(pd2[1]);
            close(pd3[0]);
            close(pd3[1]);
            execlp("uniq", "uniq", NULL);
            perror("error:");
            _exit(-1);
        }
    }
    else
    {
        wait(NULL);
        wait(NULL);
        wait(NULL);
        dup2(pd3[0], 0);
        close(pd3[0]);
        close(pd3[1]);
        execlp("wc", "wc", "-l", NULL);
        perror("error:");
    }
    return 0;
}

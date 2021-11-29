#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int count_args = 0;
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            int f_entrada = open(argv[i + 1], O_RDONLY);
            if (f_entrada == -1)
            {
                perror("error: ");
                return -1;
            }
            dup2(f_entrada, 0);
            count_args=count_args+2;
        }

        if (strcmp(argv[i], "-o") == 0)
        {
            int f_saida = open(argv[i + 1], O_WRONLY | O_CREAT, 0666);
            if (f_saida == -1)
            {
                perror("error: ");
                return -1;
            }
            dup2(f_saida, 1);
            count_args=count_args + 2;
        }
    }
    char *copy_args[10];
    i = 0;

    while (count_args < argc)
    {
        count_args++;
        copy_args[i] = argv[count_args];
        i++;
    }
    execvp(copy_args[0], copy_args);
    perror("error: ");
    return -1;

    return 0;
}
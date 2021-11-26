#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define X 3
#define Y 1000000

int mat[X][Y]; // variaveis globais sao 0 por default
// é melhor alocar global porque o seu tamanho nao cabe na stack

int main(int argc, const char *argv[])
{

    int pid;
    int n = atoi(argv[1]);
    int find = 0;
    int status;

    mat[0][2000] = n;
    mat[2][2356] = n;
    mat[1][234567] = n;

    for (int i = 0; i < X; i++)
    {
        pid = fork();

        switch (pid)
        {
        case 0:
            for (int aux = 0; aux <= Y; aux++)
            {
                if (mat[i][aux] == n)
                {

                    printf("Processo com pid=%d encontrou o número na linha %d e coluna %d\n", getpid(), i, aux);
                    exit(1);
                }
            }
            _exit(0);
            break;
        case -1:
            perror("erro a criar processo");
            return -1;
            break;
        }
    }

    for (int i = 0; i < X; i++) //pai
    {
        wait(&status);
        if (WIFEXITED(status))
        {
            if (WEXITSTATUS(status) == 1)
                find = 1;
        }
    }

    if (find == 0)
        printf("O número não foi encontrado\n");

    return 0;
}
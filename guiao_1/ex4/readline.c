#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t readln(int fd, char *buf, ssize_t nbyte)
{
    int n, i, j = 0;
    while ((n = read(fd, buf, nbyte)) > 0)
    {
        for (j = 0; j < n; j++)
        {
            if (buf[j] == '\n')
            {
                break;
            }
            else
                i++;
        }
    }
    /*int offset = i - nbyte;
    int w = lseek(fd, 0, SEEK_CUR);
    puts("\n");
    puts("offset");
    printf("%d\n", w);*/

    return i;
}

int main(int argc, char *argv[])
{
    int n = 1;
    int fd;
    char buffer[20];
    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            perror("Erro a abrir ficheiro");
        }
    }
    while ((n = readln(fd, buffer, 20)) > 0)
    {

        write(1, buffer, n);
    }
    close(fd);
    return 0;
}
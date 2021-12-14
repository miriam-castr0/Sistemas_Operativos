#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

int charcount = 0;

ssize_t readln(int fd, char *buf, ssize_t nbyte)
{
    int n, i = 0;


    while ((n = read(fd, buf, nbyte)) > 0)
    {
        while (buf[i] != '\n' && i < strlen(buf))
        {
            i++;
            charcount++;
        }
       
        if (buf[i] == '\n' )
        {
            i++;
            charcount++;
            break;
        }
        if(i>=strlen(buf)) break;

    }

    lseek(fd, charcount, SEEK_SET);

    return i;
}

int main(int argc, char *argv[])
{
    int n = 0;
    int fd;
    char buffer[MAX];
    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            perror("Erro a abrir ficheiro");
        }
    }
    while ((n = readln(fd, buffer, MAX)) > 0)
    {
        //printf("%d\n", n);
        write(1, buffer, n);
    }
    close(fd);
    return 0;
}
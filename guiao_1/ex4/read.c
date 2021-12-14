#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int charcount=0;

ssize_t readln(int fd, char *buf, ssize_t nbyte)
{
    int n, i = 0;
   
    while ((n = read(fd, buf, nbyte)) > 0)
    {  
        while(buf[i]!='\n'&&i<sizeof(buf))
        {   
            i++;
            charcount++;
        }
        i++;
        charcount++;
        break;
    }
    lseek(fd, charcount, SEEK_SET);
    

    return i;
}

int main(int argc, char *argv[])
{
    int n = 0;
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
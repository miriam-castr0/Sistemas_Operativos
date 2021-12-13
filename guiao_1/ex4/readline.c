#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int readln(int filedes, void *buf, int nbyte)
{
    char *buf2 = (char *)buf; //buffer
    int i = 0;                ///contadores
    int j = 0;

    while ((j = read(filedes, buf2, nbyte)) != -1) //enquanto houver algo para ler lê
    {
        if (*buf2 == '\n') //se clicar enter
        {

            return i - 1;
        }
        else //se
        {
            i++; //incrementa numero de linhas
        }
    }

    return -1;
}

int main(int argc, char **argv)
{
    char buf[20];
    int nbyte = 1;
    //int i=readln(0,buf,nbyte);

    int fileID;
    char buff[20];
    int count;
    int lineCount = 0;
    char lineNum[8], lastChar = '\n';
    int x, y;
    char *charPtr;
    for (x = 1; x < argc; x++)
    {
        fileID = open(argv[1], O_RDONLY);

        count = 20;

        while (count == 20)
        {
            count = read(fileID, buff, 20);

            charPtr = buff;
            for (y = 0; y < count; y++)
            {
                if (lastChar == '\n')
                {
                    lineCount++;
                    sprintf(lineNum, "\t%d  ", lineCount);
                    write(1, lineNum, strlen(lineNum));
                }

                lastChar = *charPtr;
                write(1, charPtr++, 1);
            }
        }

        close(fileID);
    }

    return 0;
}
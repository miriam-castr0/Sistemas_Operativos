#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv){

    char c;
    int f=open("fifo", O_RDONLY);
    int f1=open("log.txt", O_CREAT | O_WRONLY, 0666);

    while(read(f, &c, 1)!=0)
        write(f1, &c, 1);






    return 0;

}
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char c;
    int f=open("fifo", O_RDONLY);
    while(read(f, &c, 1)!=0)
        write(1, &c, 1);






    return 0;

}
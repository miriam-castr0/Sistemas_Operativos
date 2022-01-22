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
    int f=open("fifo", O_WRONLY);
    if(strlen(argv[1])!=0){
        write(f, argv[1], strlen(argv[1]));      
    }
    
    
    close(f);





    return 0;

}
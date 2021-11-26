#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

ssize_t readln(int fd, char *line, size_t size);

int main(int argc, const char *argv[]){

    int file1;
    int bytes;
    char s[100];

    file1=open(argv[1], O_RDONLY);

    if(file1 == -1){
        perror("fail to open");
        exit(1);
    }


    bytes=readln(file1, s, sizeof(s));
    
    printf("\nnumber of read bytes: %d\n", bytes);

    close(file1);


    return 0;
}

ssize_t readln(int fd, char *line, size_t size){
    int i=0, n=0;
    char ln;

    while((n=read(fd, &ln , sizeof(ln)))>0 && ln!='\n'){
        line[i]=ln;
        i++; 
    }
    write(1, line, sizeof(line));
    return i;
    }
    
    





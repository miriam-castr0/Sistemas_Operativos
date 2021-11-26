#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bytes;
ssize_t readln(int fd, char *line, size_t size);

int main(int argc, const char *argv[]){

    int file1;

    int n=0, i=0;
    
    char ch[4096];

    file1=open(argv[1], O_RDONLY);

    if(file1 == -1){
        perror("fail to open");
        exit(1);
    }

    while((n=readln(file1, ch, sizeof(ch)))>0){
        i++;
        
        printf("%d  %s", i, ch);

    }
   
        
    close(file1);


    return 0;
}

ssize_t readln(int fd, char *line, size_t size){
    int i=0, j=0;
    char ch[size];

    read(fd, ch, sizeof(ch));
       
    while(read(fd, ch, sizeof(ch))>0){
        i=0;
        j=0;
        
        for(j=0;j<size; j++){
            line[i]=ch[j];
            if(ch[j] == '\n'){
                
                return i;
            }
            if(j==size-1){
                return i;
            }
            i++;
        }
        
    }





    
    return i;
    }
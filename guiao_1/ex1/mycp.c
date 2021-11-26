#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 1024


int main(){

    int file1, file2;
    char *s = (char*) malloc(size* sizeof(char));

    file1=open("/home/miriam/Desktop/SO/guiao_1/ex1/file1.txt", O_RDONLY);
    file2=open("/home/miriam/Desktop/SO/guiao_1/ex1/file2.txt", O_CREAT | O_WRONLY, 0666);


    if(file1 == -1){
        perror("fail to open");
        exit(1);
    }
    
    int n=read(file1, s, size);
    
    write(file2, s, n);

    close(file1);
    close(file2);
    free(s);





    return 0;
}

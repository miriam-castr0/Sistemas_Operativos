#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 1024


int main(){
    int n;
    char s[1024];

    while((n=read(0, s, sizeof(s)))>0){//0 -> read in stdin
        write(1, s, n); //1 -> write in stdout
    } 
        

    return 0;
}
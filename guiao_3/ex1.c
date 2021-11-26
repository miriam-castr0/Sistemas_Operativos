#include <unistd.h>
#include <stdio.h>

int main(){

    execl("/bin/ls", "/bin/ls", "-l", NULL);
    perror("ls:");
    return -1;



    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){

    for(int i; i<argc; i++)
        printf("Argv[%d]: %s\n", i, argv[i]);

    return 0;
}
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#define size 6

int main(int argc, char **argv) {
    int *vector = (int *)malloc(size * sizeof(int));
    
    //create vector
    for(int i=0; i<size; i++){
        vector[i] = rand() % 10000;
    }

    //print vector
    for(int j=0; j<size; j++){
        printf("%i ", vector[j]);
        }

    //Testar a função find
    printf("N: %i\n", find(vector, size, 3));

    //Testar a função fill
    fill(vector, size+1, 6);
    for(int j=0; j<size+1; j++){
        printf("%i ", vector[j]);
        }

    //Libertar o espaço da memória
    free(vector);

    

    return 0;
}
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int find(int *vector, int size, int value) {
    int i = 0;
    for (i = 0; i < size; i++) {
        if (vector[i] == value) {
            //se vector[i] for igual a value retorna i (indice)
            //que tem esse valor
            return i;
        }
    }
    //retorna -1 se não encontrar um indice do array
    // cujo valor seja igual a value
    return -1;
}

void fill(int *vector, int size, int value) {
    vector = (int *)realloc(vector, size * sizeof(int));
    vector[size - 1] = value;
}
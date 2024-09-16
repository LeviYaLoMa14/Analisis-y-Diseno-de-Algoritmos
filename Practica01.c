#include <stdio.h>
int remover_duplicados(int* numeros, int numsSize);
int main() {
    int numeros[] = {1, 2, 2, 3, 4, 4, 5, 6, 6};
    int size = sizeof(numeros) / sizeof(numeros[0]);
    int k = remover_duplicados(numeros, size);
    printf("Número de elementos unicos: %d\n", k);       
    printf("Arreglo despues de remover duplicados (incluyendo basura): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    return 0;
}
int remover_duplicados(int* numeros, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int j = 0;
    for (int i = 1; i < numsSize; i++) {
        if (numeros[i] != numeros[j]) {
            j++;
            numeros[j] = numeros[i];
        }
    }
    return j + 1;
}

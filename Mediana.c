#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fusionarArreglos(int arreglo1[], int tam1, int arreglo2[], int tam2, int fusionado[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < tam1 && j < tam2) {
        if (arreglo1[i] < arreglo2[j]) {
            fusionado[k++] = arreglo1[i++];
        } else {
            fusionado[k++] = arreglo2[j++];
        }
    }

    while (i < tam1) {
        fusionado[k++] = arreglo1[i++];
    }

    while (j < tam2) {
        fusionado[k++] = arreglo2[j++];
    }
}

double calcularMediana(int fusionado[], int totalElementos) {
    if (totalElementos % 2 == 0) {
        return (fusionado[totalElementos / 2 - 1] + fusionado[totalElementos / 2]) / 2.0;
    } else {
        return fusionado[totalElementos / 2];
    }
}

int main() {
    int arreglo1[] = {1, 2, 3, 4, 5};
    int arreglo2[] = {6, };
    int tam1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
    int tam2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
    int totalElementos = tam1 + tam2;
    int fusionado[totalElementos];

    clock_t inicio = clock();

    fusionarArreglos(arreglo1, tam1, arreglo2, tam2, fusionado);

    double mediana = calcularMediana(fusionado, totalElementos);

    clock_t fin = clock();

    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    printf("Mediana: %f\n", mediana);
    printf("Tiempo de ejecucion: %f segundos\n", tiempo);

    return 0;
}


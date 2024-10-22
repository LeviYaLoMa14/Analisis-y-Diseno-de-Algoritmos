#include <stdio.h>
#include <stdlib.h>

#define TAMANO_MAX_HEAP 10000

typedef struct {
    int valor;
    int idx_lista;
    int idx_elemento;
} NodoHeap;

typedef struct {
    NodoHeap heap[TAMANO_MAX_HEAP];
    int tamano;
} MinHeap;

void intercambiar(NodoHeap *a, NodoHeap *b) {
    NodoHeap temp = *a;
    *a = *b;
    *b = temp;
}

void insertarMinHeap(MinHeap *h, NodoHeap nodo) {
    h->heap[h->tamano] = nodo;
    int i = h->tamano;
    h->tamano++;

    while (i > 0 && h->heap[i].valor < h->heap[(i - 1) / 2].valor) {
        intercambiar(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

NodoHeap extraerMin(MinHeap *h) {
    NodoHeap min = h->heap[0];
    h->heap[0] = h->heap[h->tamano - 1];
    h->tamano--;

    int i = 0;
    while (2 * i + 1 < h->tamano) {
        int hijo_izq = 2 * i + 1;
        int hijo_der = 2 * i + 2;
        int menor = hijo_izq;

        if (hijo_der < h->tamano && h->heap[hijo_der].valor < h->heap[hijo_izq].valor) {
            menor = hijo_der;
        }

        if (h->heap[i].valor <= h->heap[menor].valor) break;

        intercambiar(&h->heap[i], &h->heap[menor]);
        i = menor;
    }

    return min;
}

int* fusionarListas(int** listas, int tamanoListas, int* tamanoColumnas, int* tamanoResultado) {
    MinHeap min_heap;
    min_heap.tamano = 0;
    
    int totalElementos = 0;
    for (int i = 0; i < tamanoListas; i++) {
        if (tamanoColumnas[i] > 0) {
            NodoHeap nodo = {listas[i][0], i, 0};
            insertarMinHeap(&min_heap, nodo);
            totalElementos += tamanoColumnas[i];
        }
    }
    
    int* resultado = (int*)malloc(totalElementos * sizeof(int));
    *tamanoResultado = 0;
    
    while (min_heap.tamano > 0) {
        NodoHeap minNodo = extraerMin(&min_heap);
        resultado[(*tamanoResultado)++] = minNodo.valor;
        
        if (minNodo.idx_elemento + 1 < tamanoColumnas[minNodo.idx_lista]) {
            NodoHeap nuevoNodo = {listas[minNodo.idx_lista][minNodo.idx_elemento + 1], minNodo.idx_lista, minNodo.idx_elemento + 1};
            insertarMinHeap(&min_heap, nuevoNodo);
        }
    }
    
    return resultado;
}

int main() {
    int* tamanoColumnas = (int[]){4, 4, 2};
    int* listas[] = {
        (int[]){1, 4, 5, 6},
        (int[]){1, 3, 4, 7},
        (int[]){2, 6, 8}
    };
    
    int tamanoResultado;
    int* resultado = fusionarListas(listas, 3, tamanoColumnas, &tamanoResultado);
    
    for (int i = 0; i < tamanoResultado; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");
	//printf("%d", listas[]);
    free(resultado);
    return 0;
}

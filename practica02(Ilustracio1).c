#include <stdio.h>
#include <time.h>

// Función recursiva para calcular el n-ésimo número de Fibonacci
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    // Registrar el tiempo de inicio
    clock_t start = clock();

    // Calcular el n-ésimo número de Fibonacci
    int result = fibonacci(n);

    // Registrar el tiempo de finalización
    clock_t end = clock();

    // Calcular el tiempo transcurrido
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Mostrar el resultado
    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Tiempo de ejecucion: %f segundos\n", time_taken);

    return 0;
}
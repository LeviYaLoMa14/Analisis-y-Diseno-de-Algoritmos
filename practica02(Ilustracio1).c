#include <stdio.h>
#include <time.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    clock_t start = clock();

    int result = fibonacci(n);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Tiempo de ejecucion: %f segundos\n", time_taken);

    return 0;
}
#include <stdio.h>
#include <time.h>
int Fibonacci(int n);

int main() {

    int numero;
	
    printf("Escribe el numero de elementos\n");
    scanf("%i",&numero);
    
	clock_t start = clock();
     for (int i = 1; i <=numero ; i++)
    {
        printf("%i)  %li, ", i, Fibonacci(i));
    }

    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    //printf("Fibbonacci de %d es: %d\n", numero, result);
    printf("\nTiempo de ejecucion: %f segundos\n", time_taken);
    return 0;
}

int Fibonacci(int n){

    if (n==0 || n==1)
    {
        return n;
    }else{
    	return (Fibonacci(n-1) + Fibonacci(n-2));
	}
}


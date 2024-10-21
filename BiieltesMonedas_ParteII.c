#include <stdio.h>

void minBilletesMonedas(int valor) {
    int denominaciones[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(denominaciones) / sizeof(denominaciones[0]);
    int contador = 0;

    printf("\nPara el valor %d se necesitan las siguientes monedas/billetes:\n", valor);

    for (int i = 0; i < n; i++) {
        while (valor >= denominaciones[i]) {
            valor -= denominaciones[i];
            printf("%d ", denominaciones[i]);
            contador++;
        }
    }

    printf("\nNumero total de billetes/monedas: %d\n", contador);
}

int main() {
  //Ejemplos
    int valor1 = 70;
    int valor2 = 121;

    minBilletesMonedas(valor1);
    minBilletesMonedas(valor2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

typedef struct {
    double x, y;
} Punto;

void generar_puntos_aleatorios(Punto* puntos, int n) {
    for (int i = 0; i < n; i++) {
        puntos[i].x = (rand() / (double)RAND_MAX) * 200 - 100;
        puntos[i].y = (rand() / (double)RAND_MAX) * 200 - 100;
    }
}

double distancia_euclidiana(Punto p1, Punto p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    srand(time(NULL));
    int n = 10;
    Punto* puntos = (Punto*)malloc(n * sizeof(Punto));

    generar_puntos_aleatorios(puntos, n);

    for (int i = 0; i < n; i++) {
        printf("Punto %d: (%f, %f)\n", i, puntos[i].x, puntos[i].y);
    }

    double min_distancia = DBL_MAX;
    Punto mejor_par[2];

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distancia = distancia_euclidiana(puntos[i], puntos[j]);
            printf("Distancia entre Punto %d y Punto %d: %f\n", i, j, distancia);

            if (distancia < min_distancia) {
                min_distancia = distancia;
                mejor_par[0] = puntos[i];
                mejor_par[1] = puntos[j];
            }
        }
    }

    printf("El par de puntos más cercanos es: \n");
    printf("Punto 1: (%f, %f)\n", mejor_par[0].x, mejor_par[0].y);
    printf("Punto 2: (%f, %f)\n", mejor_par[1].x, mejor_par[1].y);
    printf("Con una distancia de: %f\n", min_distancia);

    free(puntos);
    return 0;
}

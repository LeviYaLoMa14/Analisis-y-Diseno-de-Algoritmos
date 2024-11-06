#include <iostream>
#include <vector>
#include <algorithm>

int maximoAgua(std::vector<int>& alturas) {
    int izquierda = 0;
    int derecha = alturas.size() - 1;
    int max_area = 0;

    while (izquierda < derecha) {
        int area = (derecha - izquierda) * std::min(alturas[izquierda], alturas[derecha]);
        max_area = std::max(max_area, area);

        if (alturas[izquierda] < alturas[derecha]) {
            izquierda++;
        } else {
            derecha--;
        }
    }

    return max_area;
}

int main() {
    std::vector<int> alturas1 = {1, 8, 6, 2, 5, 4, 8, 3, 7, 8};
    std::cout << "Máxima cantidad de agua (Ejemplo 1): " << maximoAgua(alturas1) << std::endl;

    std::vector<int> alturas2 = {1, 1, 2, 1, 3};
    std::cout << "Máxima cantidad de agua (Ejemplo 2): " << maximoAgua(alturas2) << std::endl;
     
	std::vector<int> alturas3 = {4, 5, 3, 2, 4, 5, 6, 8, 9, 0};
	std::cout << "Máxima cantidad de agua (Ejemplo 3): " << maximoAgua(alturas3) << std::endl;


    return 0;
}

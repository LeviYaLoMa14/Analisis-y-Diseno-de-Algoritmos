#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int required_sum = k * threshold;  // Suma mínima necesaria
    int current_sum = 0;  // Suma de la ventana actual
    int count = 0;

    // Calcula la suma de los primeros k elementos
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }

    // Verifica si la suma de la primera ventana es válida
    if (current_sum >= required_sum) {
        count++;
    }

    // Desliza la ventana por el arreglo
    for (int i = k; i < arr.size(); i++) {
        current_sum += arr[i] - arr[i - k];  // Desliza la ventana sumando el nuevo elemento y restando el anterior
        if (current_sum >= required_sum) {
            count++;
        }
    }

    return count;
}

int main() {
    // Ejemplo 1
    vector<int> arr1 = {2, 2, 2, 2, 5, 5, 5, 8};
    int k1 = 3, threshold1 = 4;
    cout << "Resultado Ejemplo 1: " << numOfSubarrays(arr1, k1, threshold1) << endl;

    // Ejemplo 2
    vector<int> arr2 = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k2 = 3, threshold2 = 5;
    cout << "Resultado Ejemplo 2: " << numOfSubarrays(arr2, k2, threshold2) << endl;

    return 0;
}

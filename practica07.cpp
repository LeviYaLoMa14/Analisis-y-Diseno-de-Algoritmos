#include <iostream>
#include <string>

std::string comprimir(const std::string& palabra) {
    std::string resultado;
    int longitud = palabra.size();
    
    for (int i = 0; i < longitud;) {
        char caracter = palabra[i];
        int conteo = 0;


        while (i < longitud && palabra[i] == caracter && conteo < 9) {
            conteo++;
            i++;
        }

        
        resultado += std::to_string(conteo) + caracter;
    }

    return resultado;
}

int main() {
    std::string palabra1 = "abcdeefghijklmnopqrstuvwxyz";
    std::string palabra2 = "aaaaaaccabbdeefffgggghhhhhiiiiii";

    std::cout << "Resultado 1: " << comprimir(palabra1) << std::endl; 
    std::cout << "Resultado 2: " << comprimir(palabra2) << std::endl; 

    return 0;
}

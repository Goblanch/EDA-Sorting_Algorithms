#include <iostream>
#include <vector>
#include <utility> // para swap()
#include "../Common/VectorUtils.hpp"

/*
    Bubble Sort (Ordenación por burbuja)

    Idea general:
        - Recorremos el array varias veces
        - En cada pasada comparamos los elementos adyacentes
        - Si están en orden incorrecto, los intercambiamos
        - En cada pasada, el mayor elemento de la parte no ordenada
          "sube" hasta su posición final.
*/

void bubbleSort(std::vector<int> &v) {
    // Guardamos el tamaño del vector
    int n = (int)v.size();

    // Bucle exterior: controla el número de pasadas
    // Tras cada pasada, el elemento más grande de la
    // parte no ordenada, queda al final.
    for (int i = 0; i < n - 1; ++i) {
        // Bucle interior: recorre la parte no ordenada
        // En cada iteración comparamos parejas consecutivas.
        // Vamos reduciendo el límite superior con n - 1 - i
        // ya que lo últimos están ordenados.
        for (int j = 0; j < n - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> v = generateRandomVector(10, 0, 50);

    std::cout << "Original: ";
    printVector(v);

    bubbleSort(v);

    std::cout << "Sorted: ";
    printVector(v);

    return 0;
}
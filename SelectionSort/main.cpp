#include <iostream>
#include <vector>
#include <utility>

#include "../Common/VectorUtils.hpp"

/*
    SelectionSort (Ordenación por Selección)

    Idea general:
    - Dividimos el vector en dos partes:
        * izquierda: ya ordenada
        * derecha: sin ordenar
    - En cada iteración buscamos el mínimo de la parte sin ordenar
      y lo colocamos al principio de esa parte (intercambiándolo).

    Importante:
        - Hace pocos intercambios (máximo n - 1 swaps)
        - No es estable (puede cambiar el orden de elementos iguales)
 */

void selectionSort(std::vector<int> &v) {
    const int n = static_cast<int>(v.size());

    // i marca el inicio de la parte sin ordenar
    for (int i = 0; i < n - 1; i++) {
        // Suponemos que el mínimo está en i
        int minIndex = i;

        // Buscamos el mínimo real en el rango [i...n-1]
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        // Colocamos el mínimo encontrado en la posición i
        // (si minIndex == i, swap no hace nada relevante)
        if (minIndex != i) {
            std::swap(v[i], v[minIndex]);
        }
    }
}

int main() {
    std::vector<int> v = generateRandomVector(10, 0, 50);

    std::cout << "Antes: ";
    printVector(v);

    selectionSort(v);

    std::cout << "Despues: ";
    printVector(v);

    return 0;
}
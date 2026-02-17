#include <iostream>
#include <vector>
#include <utility>
#include "../Common/VectorUtils.hpp"

/*
    BubbleSort Mejorado (OptimizedBubbleSort)

    Mejora sobre BubbleSort:
        - Se añade una bandera (swapped).
        - Si en una pasada completa NO se hace ningún intercambio,
          significa que el vector ya está ordenado y podemos parar antes.

    Ventaja: mejor caso pasa a ser O(n) (cuando ya está ordenado).
*/

void optimizedBubbleSort(std::vector<int>& v) {
    const int n = static_cast<int>(v.size());

    // Recorremos pasadas como en BubbleSort, pero podemos cortar antes.
    for (int i = 0; i < n - 1; ++i) {
        // Indica si en esta pasada hubo un intercambio
        bool swapped = false;

        // Recorremos solo la parte no ordenada (los últimos "i" ya están ordenados)
        for (int j = 0; j < n-1-i; ++j) {
            // Intercambiamos si el par está desordenado
            if (v[j] > v[j+1]) {
                std::swap(v[j], v[j+1]);
                swapped = true; // Marcamos que hubo cambios.
            }
        }

        // Si no hubo cambios, ya está ordenado. Rompemos el bucle
        if (!swapped) break;
    }
}

int main() {
    std::vector<int> v = generateRandomVector(10, 0, 50);

    std::cout << "Antes: ";
    printVector(v);

    optimizedBubbleSort(v);

    std::cout << "Despues: ";
    printVector(v);

    return 0;
}
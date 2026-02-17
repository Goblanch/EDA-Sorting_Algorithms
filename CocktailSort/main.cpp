#include <iostream>
#include <vector>
#include <utility>

#include "../Common/VectorUtils.hpp"

/*
    CocktailSort (BubbleSort bidireccional)

    Idea general:
    - Es como BubbleSort, pero en cada ciclo hace dos pasadas:
        1) De izquierda a derecha: empuja el máximo al final.
        2) De derecha a izquierda: empuja el mínimo al principio.

    Ventaja práctica: puede mejorar un poco en listas donde elementos pequeños
    están muy a la derecha o elementos grandes muy a la izquierda.
*/

void cocktailSort(std::vector<int>& v) {
    if (v.size() < 2) return;

    int left = 0; // límite izquierdo del rango no ordenado.
    int right = static_cast<int>(v.size()) - 1; // Límite derecho del rango no ordenado
    bool swapped = true;

    // Mientras haya intercambio y el rango tenga sentido
    while (swapped && left < right) {
        swapped = false;

        // 1) Pasada de izquierda a derecha
        // Si v[i] > v[i + 1], intercambiamos. El mayor se mueve hacia la derecha.
        for (int i = left; i < right; i++) {
            if (v[i] > v[i + 1]) {
                std::swap(v[i], v[i + 1]);
                swapped = true;
            }
        }

        // Si no hubo intercambio, ya está ordenado
        if (!swapped) break;
        // Después de la pasada, el elemento más grande ya está a la derecha.
        --right;

        swapped = false;

        // 2) Pasada de derecha a izquierda
        // Si v[i-1] > v[i], intercambiamos. El menor se mueve hacia la izquierda.
        for (int i = right; i > left; i--) {
            if (v[i - 1] > v[i]) {
                std::swap(v[i - 1], v[i]);
                swapped = true;
            }
        }

        // Después de la pasada, el elemento más pequeño ya está a la izquierda.
        ++left;
    }
}

int main() {
    std::vector<int> v = generateRandomVector(10, 0, 50);

    std::cout << "Antes: ";
    printVector(v);

    cocktailSort(v);

    std::cout << "Despues: ";
    printVector(v);

    return 0;
}
#include <iostream>
#include <vector>
#include "../Common/VectorUtils.hpp"

/*
    InsertionSort (Ordenación por inserción)

    Idea general:
    - Imagina que vas construyendo una mano de cartas ordenada.
    - Recorres el vector desde la segunda posición.
    - En cada paso:
        1) Guardas el valor actual (key)
        2) Desplazas a la derecha los elementos mayores que key.
        3) Insertas el key en el hueco que queda.

    Ventajas:
    - Muy bueno cuando el vector está caso ordenado.
    - Estable
    - Es in-place
*/

void insertionSort(std::vector<int> &v) {
    const int n = static_cast<int>(v.size());

    // Empezamos desde el segundo elemento porque el primero se considera ordenado
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;

        // Mientras haya elementos en la zona ordenada que sean mayores que key,
        // los desplazamos una posición a la derecha
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }

        // Insertamos key en su posición correcta
        v[j + 1] = key;
    }
}

int main() {
    std::vector<int> v = generateRandomVector(10, 0, 50);

    std::cout << "Antes: ";
    printVector(v);

    insertionSort(v);

    std::cout << "Despues: ";
    printVector(v);

    return 0;
}
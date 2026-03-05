#include <iostream>
#include <vector>
#include "VectorUtils.hpp"

// Función que une dos mitades ordenadas independientemente en un array en uno ordenado
// al completo.
static void merge(std::vector<int>& v, std::vector<int>& aux, int l, int m, int r) {
    int i = l;      // Mitad izquierda
    int j = m + 1;  // Mitad derecha
    int k = l;      // Índice en aux

    // Aquí el vector tiene dos mitades ordenadas. Una de left a mid y otra de mid + 1 a right.
    // Comprobamos si el elemento de la parte izquierda es menor o igual que el de la derecha
    // y en tal caso, añadimos en aux el menor de los dos.
    while (i <= m && j <= r) {
        // Si el menor está en la parte izquierda (v[i]), lo añado en aux e incremento
        // solo el iterador de i y aux, para comprobar si el siguiente de la izquierda,
        // sigue siendo menor que el actual de la derecha.
        if (v[i] <= v[j]) aux[k++] = v[i++]; // Primero accede a k/i y luego incrementa.
        else aux[k++] = v[j++];
    }

    // Hasta aquí, se han mezclado los elementos, pero es posible que queden elementos en algunas
    // de las mitades, por lo que añadimos primero lo que queda a la izquierda y luego a la derecha.
    while (i <= m) aux[k++] = v[i++];
    while (j <= r) aux[k++] = v[j++];

    // Copiamos el contenido de aux (ordenado) en v que es la salida.
    for (int x = l; x <= r; ++x) v[x] = aux[x];
}

// Función recursiva de ordenación (MergeSort). Divide el array v en dos y llama recursivamente
// a la ordenación en cada mitad. Al final, los une.
static void mergeSortRec(std::vector<int>& v, std::vector<int>& aux, int l, int r) {
    if (l >= r) return; // Caso base

    int m = l + (r - l) / 2;
    mergeSortRec(v, aux, l, m);
    mergeSortRec(v, aux, m + 1, r);
    merge(v, aux, l, m, r);
}

void mergeSort(std::vector<int>& v) {
    if (v.empty()) return;
    const int size = static_cast<int>(v.size());
    std::vector<int> aux(size);
    mergeSortRec(v, aux, 0, size - 1);
}

int main() {
    std::vector<int> v = {5, 2, 9, 1, 5, 6, 3};
    std::cout << "Before: " << std::endl;
    printVector(v);

    mergeSort(v);

    std::cout << "After: " << std::endl;
    printVector(v);

    return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include "VectorUtils.hpp"

static int partition(std::vector<int>& v, int l, int r) {
    int pivot = v[r];   // pivote: último elemento
    int i = l - 1;

    for (int j = l; j < r; j++) { // Recorre todos los elementos desde la izquierda (l) hasta uno antes del pivote
        if (v[j] <= pivot) {
            ++i;
            std::swap(v[i], v[j]);  // Metemos v[j] en la zona <= pivote
        }
    }

    // Colocamos el pivote en i + 1 y ahora a la izquierda del pivote, todos son menores
    // y a la derecha son mayores que el pivote. Pero ojo, no están ordenados.
    std::swap(v[i + 1], v[r]);
    return i + 1; // Índice final del pivote
}

static void quickSortRec(std::vector<int>& v, int l, int r) {
    if (l >= r) return;

    int p = partition(v, l, r);
    quickSortRec(v, l, p - 1);
    quickSortRec(v, p + 1, r);
}

void quickSort(std::vector<int>& v) {
    if (v.empty()) return;
    quickSortRec(v, 0, v.size() - 1);
}

int main() {

    std::vector<int> v = {5, 2, 9, 1, 5, 6, 3};

    std::cout << "Before: \n";
    printVector(v);

    quickSort(v);

    std::cout << "After: \n";
    printVector(v);

    return 0;
}
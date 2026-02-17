#pragma once

#include <vector>
#include <iostream>

// Imprime un vector en formato [a, b, c]
void printVector(const std::vector<int>& v);

// Genera un vector de tamaño n con valores aleatorios
std::vector<int> generateRandomVector(int n, int min = 0, int max = 100);
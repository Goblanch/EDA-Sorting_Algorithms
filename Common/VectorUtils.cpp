#include "VectorUtils.hpp"
#include <random>

void printVector(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

std::vector<int> generateRandomVector(int n, int min, int max) {
    std::vector<int> v(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < n; ++i) {
        v[i] = dis(gen);
    }

    return v;
}
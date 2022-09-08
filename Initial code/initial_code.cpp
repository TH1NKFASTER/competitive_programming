//
// Created by tfr on 08.09.2022.
//
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <functional>

using ll = long long;
using ull = unsigned long long;

template<class T, class BinaryOperation=std::function<T(T, T)>>
std::vector<T> PrefixOp(const std::vector<T> &v, BinaryOperation operation = std::plus<T>(), const T &neutral = T()) {
    std::vector<T> result(v.size() + 1);
    result[0] = neutral;
    for (unsigned i = 0; i < v.size(); ++i) {
        result[i + 1] = (operation(result[i], v[i]));
    }
    return result;
}

template<class T>
void printVector(const std::vector<T> &v) {
    for (auto &t: v) {
        std::cout << t << " ";
    }
    std::cout << "\n";
}

template<class T>
void readVector(std::vector<T> &v) {
    for (auto &t: v) {
        std::cin >> t;
    }
}

int main() {
    ull tests_in_task = 1;
    while (tests_in_task--) {

    }
}
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
class OperationOnSegmentUsingPrefixOp {


};

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

class IntMod {
public:
    IntMod() {
        number = 0;
    }

    IntMod(ull x) {
        number = x % modular;
    }


    ull number;
    const ull modular = 1000000007;
};

template<class T>
class Combinatorics {
public:
    Combinatorics() {
        factorials.resize(max_n + 1);
        factorials[0] = 1;
        for (unsigned long long i = 1; i <= max_n; ++i) {
            factorials[i] = (factorials[i - 1] * i) % modular;
        }
        inverse_factorials.resize(max_n + 1);
        for (unsigned long long i = 0; i <= max_n; ++i) {
            inverse_factorials[i] = inverse_modular(factorials[i]);
        }
    }

    T fast_power(T base, T pow) {
        if (pow == 0) {
            return 1;
        }
        T half = fast_power(base, pow / 2);
        if (pow % 2) {
            return half * half * base;
        } else {
            return half * half;
        }
    }

    T inverse_modular(T num) {
        return fast_power(num, modular - 2);
    }

    T Cnk(T n, T k) {
        return factorials[n] * inverse_factorials[k] * inverse_factorials[n - k];
    }

    T Ank(T n, T k) {
        return factorials[n] * inverse_factorials[n - k];
    }

private:
    unsigned long long max_n = 1e6;
    std::vector<T> factorials;
    std::vector<T> inverse_factorials;
    unsigned long long modular = 1000000007;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
    ull tests_in_task = 1;
    while (tests_in_task--) {

    }
}
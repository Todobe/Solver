#pragma once

#include <iostream>
#include <vector>

template<typename T>
void print(const T& t) {
    std::cout << t << " ";
}

template<typename T>
void print(const std::vector<T>& vt) {
    for (const T& t : vt) print(t);
}

template<typename T>
void debug(const T& t) {
    print(t);
    std::cout << std::endl;
}


template<typename T1, typename T2>
void debug(const T1& t1, const T2& t2) {
    print(t1);
    print(t2);
    std::cout << std::endl;
}
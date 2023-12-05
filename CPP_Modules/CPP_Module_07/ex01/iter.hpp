#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <stdexcept>
#include <iostream>

// For user defined types
template <typename T, typename F>
void iter(T a[], size_t size, void(func)(F&)) {
    if (size < 1)
        throw std::out_of_range("Error: Invalid size");

    for (size_t i = 0; i < size; i++) {
        func(a[i]);
    }
}

template <typename T>
void iter(T a[], size_t size, void(func)(T&)) {
    if (size < 1)
        throw std::out_of_range("Error: Invalid size");

    for (size_t i = 0; i < size; i++) {
        func(a[i]);
    }
}

#endif
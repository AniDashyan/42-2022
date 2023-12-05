#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <stdexcept>

int main(void) {
    try {
        const int size = 5;

        // array
        std::array<int, size> arr = {1, 2, 3, 4, 7};

        std::array<int, 5>::iterator it;
        it = easyfind(arr, 7);
        std::cout << "element was found in array: " << *it << std::endl;

        // vector
        std::vector<int> vec;
        for (int i = 0; i < size; i++)
            vec.push_back(i);

        std::vector<int>::iterator itv;
        itv = easyfind(vec, 3);
        std::cout << "element was found in vector: " << *itv << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
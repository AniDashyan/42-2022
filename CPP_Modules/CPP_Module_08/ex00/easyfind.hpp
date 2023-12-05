#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <stdexcept>
#include <string>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& Container, int value) {
    typename T::iterator it;
    it = std::find(Container.begin(), Container.end(), value);
    if (it == Container.end())
        throw std::invalid_argument("Error: value wasn't found!");

    return (it);
}
#endif

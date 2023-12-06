#include "Span.hpp"
#include <iostream>
#include <vector>

// int main() {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);

//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return (0);
// }

int main() {
    Span sp(5);
    sp.addNumber(7);
    sp.addNumber(4);
    sp.addNumber(3);
    sp.addNumber(7);
    sp.addNumber(8);
    sp.addNumber(12);
    sp.addNumber(123);

    std::vector<int> vec = sp.getVector();
    std::vector<int>::iterator it;
    int i = 0;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << "it[" << i << "]= " << *it << std::endl;
        i++;
    }

    std::cout << "longest span: " << sp.longestSpan() << std::endl;
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;

    sp.addManyNumbers((vec.begin() + 3), vec.end());
    std::vector<int> vec2 = sp.getVector();
    i = 0;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << "it[" << i << "]= " << *it << std::endl;
        i++;
    }
    return (0);
}
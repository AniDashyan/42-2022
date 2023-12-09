#include "Span.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.addNumber(8);
        // sp.addNumber(12);

        std::cout << "------- Subject Test -------" << std::endl;
        std::vector<int> vec = sp.getVector();
        std::vector<int>::iterator it;
        int i = 0;
        std::cout << "Vector: " << std::endl; 
        for (it = vec.begin(); it != vec.end(); it++)
        {
            std::cout << "vec[" << i << "]= " << *it << std::endl;
            i++;
        }

        std::cout << "--------------------------" << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "--------------------------" << std::endl << std::endl;


        Span sp2 = Span(15000);
        std::cout << "------- Test with size 15000 -------" << std::endl;
        std::vector<int> vec2;
        for (int i = 0; i < 15000; i++)
            vec2.push_back(i);

        sp2.addManyNumbers(vec2.begin(), vec2.end());

        std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp2.longestSpan() << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
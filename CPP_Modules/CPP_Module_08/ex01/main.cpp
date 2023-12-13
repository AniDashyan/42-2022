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

        std::cout << "Subject test" << std::endl;
        std::vector<int> vec = sp.getVector();
        std::vector<int>::iterator it;
        int i = 0;
        for (it = vec.begin(); it != vec.end(); it++)
        {
            std::cout << "vec[" << i << "]= " << *it << std::endl;
            i++;
        }

        std::cout << "longest span: " << sp.longestSpan() << std::endl;
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;

        // Span sp2 = Span(15000);
        Span s(10);
        std::cout << "Test 2: Adding many numbers" << std::endl;
        std::vector<int> vec2;
        int arr[7] = {1, 2, 3, 4, 5, 6, 7};
        for (int i = 0; i < 7; i++)
            vec2.push_back(arr[i]);

        s.addManyNumbers(vec2.begin(), vec2.end());
        std::vector<int>vec3 = s.getVector();
        for (size_t i = 0; i < vec3.size(); i++)
            std::cout << "vec3[" << i << "]= " << vec3.at(i) << std::endl;

        std::cout << "shortest span: " << s.shortestSpan() << std::endl;
        std::cout << "longest span: " << s.longestSpan() << std::endl;

    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
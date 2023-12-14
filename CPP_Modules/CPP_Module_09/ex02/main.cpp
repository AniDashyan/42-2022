#include "PmergeMe.hpp"
#include <iostream>


int main(int argc, char** argv) {
    if (argc > 2) {
        std::vector<std::string> args(argv + 1, argv + argc);
        for (size_t i = 0; i < args.size(); i++)
        {
            std::cout << "vec[" << i << "]= " << args[i] << std::endl;
        }
    }
    else
        std::cout << "Error: Arguments must be more than 1" << std::endl;
    return (0);
}
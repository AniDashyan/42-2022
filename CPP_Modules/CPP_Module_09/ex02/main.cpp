#include "PmergeMe.hpp"
#include <iostream>


int main(int argc, char** argv) {
    if (argc > 2) {
        try {
            PMergeMe pmg;
            pmg.parsing(argv);
            pmg.FordJohnsonVector();
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: Arguments must be more than 1" << std::endl;
    return (0);
}
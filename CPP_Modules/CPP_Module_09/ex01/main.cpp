#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc == 2)
    {
        try {
            RPN rpn;
            std::string arg(argv[1]);
            std::cout << "result: " << rpn.calculate(arg) << std::endl;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: Bad arguments!" << std::endl; 
    return (0);
}
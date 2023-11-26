#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
    if (argc == 2)
    {
        ScalarConverter::converter(argv[1]);
    }
    else
        std::cout << "❌ Error: Bad arguments! ❌" << std::endl;
        return (0);
}
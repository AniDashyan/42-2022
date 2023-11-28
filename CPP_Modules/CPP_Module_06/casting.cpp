#include <iostream>
#include <iomanip>

#define WHITESPACES  " \r\n\t\v\f"

// Types, Conversions and C-style casts
/* int main() {
    // Example 1
    // std::cout << std::fixed;
    // std::cout << std::setprecision(6);
    // std::cout << (float)7/5 << std::endl;

    // Example 2
    int result = 65;
    // short c = result;
    // unsigned short c = result;
    char c = result;
    // This cast is happening run-time
    std::cout << (short)c << std::endl; // C-style cast

    // type cast
    // std::cout << (short)result << std::endl; 

    // difference between int and short
    // std::cout << "int size: " << sizeof(result) << std::endl;
    // std::cout << "short size: " << sizeof(c) << std::endl;
    return (0);
} */

int main(int argc, char** argv) {
    if (argc == 2)
    {
        std::string literal(argv[1]);
        std::cout << "string before:" << literal  << ":" << std::endl;
        std::cout << "First not space: " <<  literal.find_first_not_of(WHITESPACES) << std::endl;
        literal.erase(0, literal.find_first_not_of(WHITESPACES));
        std::cout << "string after:" << literal  << ":" << std::endl;
        std::cout << "Last not space: " <<  literal.find_last_not_of(WHITESPACES) << std::endl;
        literal.erase(literal.find_last_not_of(WHITESPACES) + 1);
        std::cout << "string after 2nd erase:" << literal << ":"<< std::endl;
    }
    else
        std::cout << "Error: Bad arguments" << std::endl;
    return (0);
}
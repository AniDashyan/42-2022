#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) {
    if (argc == 2) {
        try {
            BitcoinExchange btc;
            std::string file(argv[1]); 
            btc.function(file);
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: Argument has to be one" << std::endl;
    return (0);
}
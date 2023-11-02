#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat b1("Jack", 120);
        ShrubberyCreationForm scf("home");
        
        std::cout << scf << std::endl;
        scf.execute(b1);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}       
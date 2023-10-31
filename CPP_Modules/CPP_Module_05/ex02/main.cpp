#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        ShrubberyCreationForm scf("home");
        home.execute();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}       
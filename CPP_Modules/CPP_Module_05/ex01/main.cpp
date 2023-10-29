#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat defb1;
        Bureaucrat b1("Jack", 15);
        Form defform;
        Form form1("Hack", 40, 30);

        std::cout << defb1 << std::endl;
        std::cout << b1 << std::endl;
        std::cout << defform << std::endl;
        std::cout << form1 << std::endl;

        b1.signForm(form1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}       
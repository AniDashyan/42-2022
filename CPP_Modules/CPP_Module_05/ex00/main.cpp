#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        // Default Constructor Check
        Bureaucrat defb;
        std::cout << defb << std::endl;
        defb.incrementGrade();
        std::cout << defb << std::endl;
        defb.decrementGrade();
        std::cout << defb << std::endl;

        // Parameter Constructor Check
        Bureaucrat b1("John", 10);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;

        // GradeTooHighException Check
        // b1.setGrade(1);
        // b1.incrementGrade();

        // GradeTooLow Exception Check
        Bureaucrat b2("Jack", 120);
        std::cout << b2 << std::endl;

        // Copy Constructor Check
        Bureaucrat b3(b1);
        std::cout << b3 << std::endl;
        b3.decrementGrade();
        std::cout << b3 << std::endl;

        // Check Copy Assignment Operator
        Bureaucrat b4;
        b4 = b2;
        std::cout << b4 << std::endl;

        Bureaucrat b5 = b4;
        std::cout << b5 << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
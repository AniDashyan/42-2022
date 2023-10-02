#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("John", 100);
        std::cout << b1 << std::endl;
        Bureaucrat b2("Jack", 150);
        std::cout << b2 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
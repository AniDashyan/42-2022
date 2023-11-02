#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b1("Jack", 120);
        Bureaucrat b2("Hack", 40);
        Bureaucrat b3("BlackJack", 2);
        ShrubberyCreationForm scf("home");
        RobotomyRequestForm rrf("robot");
        PresidentialPardonForm ppf("president");

        b1.incrementGrade();
        b2.decrementGrade();

        b1.signForm(scf);
        b2.signForm(rrf);
        b3.signForm(ppf);
        std::cout << scf << std::endl;
        std::cout << rrf << std::endl;
        std::cout << ppf << std::endl;
        
        scf.execute(b1);
        rrf.execute(b2);
        ppf.execute(b1);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}       
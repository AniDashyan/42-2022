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
        std::cout << scf << std::endl;
        RobotomyRequestForm rrf("robot");
        std::cout << rrf << std::endl;
        PresidentialPardonForm ppf("president");
        std::cout << ppf << std::endl;

        b1.signForm(scf);
        b2.signForm(rrf);
        b3.signForm(ppf);
       
        scf.execute(b1);
        rrf.execute(b2);
        ppf.execute(b3);

        b1.executeForm(scf);
        b2.executeForm(rrf);
        b3.executeForm(ppf);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}       
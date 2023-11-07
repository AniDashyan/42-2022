#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        AForm* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");

        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Jack");

        AForm *ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Hack");

        AForm *nef;
        nef = someRandomIntern.makeForm("hello", "Blah Blah");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
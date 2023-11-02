#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern  someRandomIntern;
        Form*   rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}       
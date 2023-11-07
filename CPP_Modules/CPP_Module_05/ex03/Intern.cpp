#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Default Constructor of Intern is called" << std::endl;
}

Intern::Intern(const Intern& other)  {
    (void)other;
    std::cout << "Copy Constructor of Intern is called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Copy Assignment operator is called" << std::endl;
    return (*this);
}

Intern::~Intern() {
    std::cout << "Destructor of Intern is called" << std::endl;
}

const char* Intern::NotExistingForm::what() const throw() {
    return ("❌ Form name does not exist ❌");
}

AForm* Intern::makeForm(std::string formName, std::string targetForm) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;
    for (int i = 0; i < 3; i++)
        if (formName == formNames[i])
            index = i;

    switch (index) {
        case 0:
            std::cout << "Intern creates ShrubberyCreationForm form " << std::endl;
            return (new ShrubberyCreationForm(targetForm));
        case 1:
            std::cout << "Intern creates RobotomyRequest form " << std::endl;
            return (new RobotomyRequestForm(targetForm));
        case 2:
            std::cout << "Intern creates PresidentialPardon form " << std::endl;
            return (new PresidentialPardonForm(targetForm));
        default:
            throw NotExistingForm();
    }
}
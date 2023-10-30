#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {
    std::cout << "Constructor of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : m_target(target) {
    std::cout << "Constructor with parameters of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
    std::cout << "Copy Constructor of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const &ShrubberyCreationForm other)
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::endl << "Destructor of ShrubberyCreationForm is called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    std::ofstream os;
    executor.open(this->target + "_shrubbery");
}
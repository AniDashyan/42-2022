#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), m_target("defTarget") {
    std::cout << "Constructor of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyForm", 145, 137), m_target(target) {
    std::cout << "Constructor with parameters of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : m_target(other.m_target) {
    std::cout << "Copy Constructor of ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
    {
        this->m_target = other.m_target;
    }
    std::cout << "Copy Assignment Operator of ShrubberyCreationForm is called" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor of ShrubberyCreationForm is called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    std::ofstream os(this->m_target + "_shrubbery");
    os << " *    *    ()   *   * " << std::endl;
    os << "*        * /\\         *" << std::endl;
    os << "      *   /i\\    *  *" << std::endl;
    os << "    *     o/\\  *      *" << std::endl;
    os << " *       ///\\i\\    *" << std::endl;
    os << "     *   /*/o\\  *    *" << std::endl;
    os << "   *    /i//\\*\\      *" << std::endl;
    os << "        /o/*\\i\\   *" << std::endl;
    os << "  *    //i//o\\\\     *" << std::endl;
    os << "    * /*////\\\\i\\ *" << std::endl;
    os << " *    //o//i\\*\\\\   *" << std::endl;
    os << "   * /i///*/\\\\\\o\\   *" << std::endl;
    os << "  *    *   ||     *" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, const ShrubberyCreationForm& other) {
    stream << "ShrubberyCreationForm name: " << other.getName() << ",  is_signed: " << other.getSigned() << ", required grade: " << other.getRequiredGrade() << ", executed grade: " << other.getExecutedGrade();

    return (stream);
}
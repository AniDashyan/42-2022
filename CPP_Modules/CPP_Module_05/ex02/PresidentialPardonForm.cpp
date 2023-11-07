#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentForm", 25, 5), m_target("Default") {
    std::cout << "Constructor of PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentForm", 25, 5), m_target(target) {
    std::cout << "Constructor with parameters of PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentForm", 25, 5), m_target(other.m_target) {
    std::cout << "Copy Constructor of PresidentalPardonForm is called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
    {
        this->m_target = other.m_target;
    }
    std::cout << "Copy Assignment Operator of PresidentialPardonForm is called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor of PresidentialPardonForm is called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    
    std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, const PresidentialPardonForm& other) {
    stream << "PresidentialPardonForm name: " << other.getName() << ",  is_signed: " << other.getSigned() << ", required grade: " << other.getRequiredGrade() << ", executed grade: " << other.getExecutedGrade();

    return (stream);
}
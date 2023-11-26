#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), m_target("defTarget") {
    std::cout << "Constructor of RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyForm", 72, 45), m_target(target) {
    std::cout << "Constructor with parameters of RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyForm", 72, 45), m_target(other.m_target) {
    std::cout << "Copy Constructor of RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
    {
        this->m_target = other.m_target;
    }
    std::cout << "Copy Assignment Operator of RobotomyRequestForm is called" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor of RobotomyRequestForm is called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    std::cout << "Drrrr Drrr Drr Dr Dr Dr Drr Drrr Drrrr" << std::endl;
    srand((unsigned)time(NULL));
    if ((1 + (std::rand() % 100)) % 2)
        std::cout << this->m_target << " has been robotomized successfully 50\% of the time" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, const RobotomyRequestForm& other) {
    stream << "RobotomyRequestForm name: " << other.getName() << ",  is_signed: " << other.getSigned() << ", required grade: " << other.getRequiredGrade() << ", executed grade: " << other.getExecutedGrade();

    return (stream);
}
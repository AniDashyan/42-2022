#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

AForm::AForm() : m_name("Default"), m_is_signed(false), m_req_grade(20), m_exec_grade(30)
{
    std::cout << "Default Constructor of AForm is called" << std::endl;
}

AForm::AForm(const std::string& name, unsigned int req_grade, unsigned int exec_grade) 
   : m_name(name), m_is_signed(false), m_req_grade(req_grade), m_exec_grade(exec_grade) {
    // this->exec_grade = exec_grade;
    if (this->m_req_grade < 1 || this->m_exec_grade < 1)
        throw GradeTooHighException();
    else if (this->m_req_grade > 150 || this->m_exec_grade > 150)
        throw GradeTooLowException();
    std::cout << "Constructor of AForm with parameters was called" << std::endl;
}

AForm::AForm(const AForm& other)
    : m_name(other.m_name), m_is_signed(other.m_is_signed), m_req_grade(other.m_req_grade), m_exec_grade(other.m_exec_grade) {
        std::cout << "Copy Constructor of AForm is called" << std::endl;
}

// AForm AForm::operator=(const AForm& other) {
//     if (this != &other)
//     {
//         // Do nothing
//         // this->m_name = other.m_name;
//         // this->m_is_signed = other.m_is_signed;
//         // this->m_req_grade = other.m_req_grade;
//         // this->m_exec_grade = this->m_exec_grade;
//     }
//     std::cout << "Copy Assignment of AForm is called" << std::endl;
//     return (*this);
// }

AForm::~AForm() {
    std::cout << "Destructor of AForm " << this->m_name << " is called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("❌ Grade of Form is too high ❌");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("❌ Grade of Form is too low ❌");
}

const char* AForm::FormNotSigned::what() const throw() {
    return ("❌ Form is not signed ❌");
}

std::string AForm::getName() const {
    return (this->m_name);
}

bool AForm::getSigned() const {
    return (this->m_is_signed);
}

unsigned int AForm::getRequiredGrade() const {
    return (this->m_req_grade);
}

unsigned int AForm::getExecutedGrade() const {
    return (this->m_exec_grade);
}

void AForm::beSigned(Bureaucrat& b) {
    if (b.getGrade() > 150)
        throw GradeTooLowException();
    else if (b.getGrade() <= this->m_req_grade)
        this->m_is_signed = true;
}

std::ostream& operator<<(std::ostream &stream, const AForm& other) {
    stream << "AForm name: " << other.getName() << ",  is_signed: " << other.getSigned() << ", required grade: " << other.getRequiredGrade() << ", executed grade: " << other.getExecutedGrade();

    return (stream);
}
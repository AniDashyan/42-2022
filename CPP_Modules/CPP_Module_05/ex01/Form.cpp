#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() 
{
    std::cout << "Default Constructor of Form is called" << std::endl;
}

Form::Form(const std::string& name, const int req_grade, const int exec_grade) 
   : m_name(name), m_is_signed(0), m_req_grade(req_grade), m_exec_grade(exec_grade) {
    if (m_req_grade < 1 || m_exec_grade < 1)
        throw GradeTooHighException();
    else if (m_req_grade > 150 || m_exec_grade > 150)
        throw GradeTooLowException();
    std::cout << "Constructor of Form with parameters was called" << std::endl;
}

Form::Form(const Form& other)
    : m_name(other.m_name), m_is_signed(other.m_is_signed), m_req_grade(other.m_req_grade), m_exec_grade(other.m_exec_grade) {

}

Form Form::operator=(const Form& other) {
    if (this != &other)
    {
        // Do nothing
        // this->m_name = other.m_name;
        // this->m_is_signed = other.m_is_signed;
        // this->m_req_grade = other.m_req_grade;
        // this->m_exec_grade = this->m_exec_grade;
    }
    std::cout << "Copy Assignment of Form is called" << std::endl;
    return (*this);
}

Form::~Form() {
    std::cout << "Destructor of Form " << this->m_name << " is called" << std::endl;
}

// Exception clases
const char* Form::GradeTooHighException::what() const throw() {
    return ("❌ Grade of Form is too high ❌");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("❌ Grade of Form is too low ❌");
}


// Getters
std::string Form::getName() const {
    return (this->m_name);
}

bool Form::getSigned() const {
    return (this->m_is_signed);
}

int Form::getRequiredGrade() const {
    return (this->m_req_grade);
}

int Form::getExecutedGrade() const {
    return (this->m_exec_grade);
}

void Form::beSigned(Bureaucrat& b) {
    if (b.getGrade() < 150)
        throw GradeTooLowException();
    else if (b.getGrade() <= this->m_req_grade)
        this->m_is_signed = 1;
}

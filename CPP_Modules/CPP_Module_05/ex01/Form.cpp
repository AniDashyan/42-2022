#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

Form::Form() : m_name("Default"), m_is_signed(false),m_req_grade(20), m_exec_grade(30)
{
    std::cout << "Default Constructor of Form is called" << std::endl;
}

Form::Form(const std::string& name, unsigned int req_grade, unsigned int exec_grade) 
   : m_name(name), m_is_signed(false), m_req_grade(req_grade), m_exec_grade(exec_grade) {
    // this->exec_grade = exec_grade;
    if (this->m_req_grade < 1 || this->m_exec_grade < 1)
        throw GradeTooHighException();
    else if (this->m_req_grade > 150 || this->m_exec_grade > 150)
        throw GradeTooLowException();
    std::cout << "Constructor of Form with parameters was called" << std::endl;
}

Form::Form(const Form& other)
    : m_name(other.m_name), m_is_signed(other.m_is_signed), m_req_grade(other.m_req_grade), m_exec_grade(other.m_exec_grade) {
        std::cout << "Copy Constructor of Form is called" << std::endl;
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

const char* Form::GradeTooHighException::what() const throw() {
    return ("❌ Grade of Form is too high ❌");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("❌ Grade of Form is too low ❌");
}

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
    if (b.getGrade() > 150)
        throw GradeTooLowException();
    else if (b.getGrade() <= this->m_req_grade)
        this->m_is_signed = true;
}

std::ostream& operator<<(std::ostream &stream, const Form& other) {
    std::stringstream str;
    std::string req_grade;
    std::string exec_grade;

    str << other.getRequiredGrade();
    str >> req_grade;

    str << other.getExecutedGrade();
    str >> exec_grade;
    stream << "Form name: " << other.getName() << ",  is_signed: " << other.getSigned() << ", required grade: " << req_grade << ", executed grade: " << exec_grade;

    str.str(std::string()); // Clear stringstream
    return (stream);
}
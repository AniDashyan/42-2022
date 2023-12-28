#include "Bureaucrat.hpp"
#include "Form.hpp"+
#include <iostream>

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(45) {
    std::cout << "Default Constructor of Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : m_name(name), m_grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Constructor with parameters of Bureaucrat is called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): m_name(other.m_name), m_grade(other.m_grade) {
   std::cout << "Copy Constructor of Bureaucrat is called" << std::endl; 
}

Bureaucrat Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
    {
        // TODO: const_cast
        // (std::string)this->m_name = other.m_name;
        this->m_grade = other.m_grade;
    }
    std::cout << "Copy Assignment Operator is called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor of Bureaucrat is called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("❌ Grade of Bureaucrat is too high ❌");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("❌ Grade of Bureaucrat is too low ❌");
}

std::string Bureaucrat::getName() const {
    return (this->m_name);
}

int Bureaucrat::getGrade() const {
    return (this->m_grade);
}

void Bureaucrat::setGrade(int grade) {
    this->m_grade = grade;
}

void Bureaucrat::incrementGrade() {
    --(this->m_grade);
    if (this->m_grade < 1)
        throw GradeTooHighException();
    std::cout << "Grade of Bureaucrat " << this->m_name << " has been incremented\n";
}

void Bureaucrat::decrementGrade() {
    ++(this->m_grade);
    if (this->m_grade > 150)
        throw GradeTooLowException();
    std::cout << "Grade of Bureaucrat " << this->m_name << " has been decremented\n";
}

void Bureaucrat::signForm(Form& form) {
    try
    {
        form.beSigned(*this);
        std::cout << "Bureacrat " << this->m_name << " signed " << "form: " << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Bureacrat " << this->m_name << " couldn’t sign form because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& other) {
    stream << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;

    return (stream);
}
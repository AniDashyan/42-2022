#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() {
    std::cout << "Constructor of Bureaucrat is called" << std::endl;
}

Bureaucrat:: Bureaucrat(const std::string& name, int grade) : m_name(name), m_grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Parameter Constructor called\n";
}

// Throw exception in constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other): m_name(other.m_name), m_grade(other.m_grade) {
   std::cout << "Copy Constructor of Bureaucrat is called" << std::endl; 
}

Bureaucrat Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Copy Assignment Operator is called" << std::endl;
    if (this != &other)
    {
        (std::string)this->m_name = other.m_name;
        this->m_grade = other.m_grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor of Bureaucrat is called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    std::cout << "❌ Grade of BureauCrat is too high ❌" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    std::cout << "❌ Grade of BureauCrat is too low ❌" << std::endl;
}

std::string Bureaucrat::getName() const {
    return (this->m_name);
}

int Bureaucrat::getGrade() const {
    return (this->m_grade);
}

void Bureaucrat::incrementGrade() {
    --(this->m_grade);
}

void Bureaucrat::decrementGrade() {
    ++(this->m_grade);
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& other) {
    stream << (other.getName() + ",  bureaucrat grade ").append(other.getGrade());
}
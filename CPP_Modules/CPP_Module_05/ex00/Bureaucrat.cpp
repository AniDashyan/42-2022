#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(45) {
    std::cout << "Constructor of Bureaucrat is called" << std::endl;
}

Bureaucrat:: Bureaucrat(const std::string& name, int grade) : m_name(name), m_grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Parameter Constructor of Bureaucrat called\n";
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
    return ("❌ Grade of BureauCrat is too high ❌");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("❌ Grade of BureauCrat is too low ❌");
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
    std::cout << "Grade of Bureaucrat " << this->m_name << " incremented\n";
}

void Bureaucrat::decrementGrade() {
    ++(this->m_grade);
    if (this->m_grade > 150)
        throw GradeTooLowException();
    std::cout << "Grade of Bureaucrat " << this->m_name << " decremented\n";
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& other) {
    // Making int to string using stringstream
    std::stringstream str;
    std::string grade;
    str << other.getGrade();
    str >> grade;

    // << operator overload
    stream << other.getName() + ", bureaucrat grade " + grade;
    return (stream);
}
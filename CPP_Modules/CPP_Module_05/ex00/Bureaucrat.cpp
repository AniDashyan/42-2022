#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() {
    std::cout << "Constructor of Bureaucrat is called" << std::endl;
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

// class GradeTooHighException : public std::exception {
//         public:
//             const char* what() const throw();
// };

// class GradeTooLowException : public std::exception {
//         public:
//             const char* what() const throw();
// };

std::string Bureaucrat::getName() const {
    return (this->m_name);
}

int Bureaucrat::getGrade() const {
    return (this->m_grade);
}

void Bureaucrat::incrementGrade() {
    this->m_grade--;
}

void Bureaucrat::decrementGrade() {
    this->m_grade++;
}
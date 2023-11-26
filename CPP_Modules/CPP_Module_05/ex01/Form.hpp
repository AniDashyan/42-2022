#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form {
    public:
        Form();
        Form(const std::string& name, unsigned int req_grade, unsigned int exec_grade);
        Form(const Form& other);
        Form operator=(const Form& other);
        ~Form();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        // Getters
        std::string getName() const;
        bool getSigned() const;
        int getRequiredGrade() const;
        int getExecutedGrade() const;

        void beSigned(Bureaucrat& b); // this function changes the form status to signed if the grade is high enough
 
    private:
        const std::string m_name;
        bool m_is_signed;
        const int m_req_grade;
        const int m_exec_grade;
};

std::ostream& operator<<(std::ostream &stream, const Form& other);

#endif
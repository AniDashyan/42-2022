#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm {
    public:
        AForm();
        AForm(const std::string& name, unsigned int req_grade, unsigned int exec_grade);
        AForm(const AForm& other);
        // AForm operator=(const AForm& other);
        ~AForm();

        // Exception clases
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormNotSigned : public std::exception {
            public:
                const char* what() const throw();
        };

        // Getters
        std::string getName() const;
        bool getSigned() const;
        unsigned int getRequiredGrade() const;
        unsigned int getExecutedGrade() const;

        void beSigned(Bureaucrat& b);

        virtual void execute(Bureaucrat const & executor) const = 0;
 
    private:
        const std::string m_name;
        bool m_is_signed;
        const unsigned int m_req_grade;
        const unsigned int m_exec_grade;
};

std::ostream& operator<<(std::ostream &stream, const AForm& other);

#endif
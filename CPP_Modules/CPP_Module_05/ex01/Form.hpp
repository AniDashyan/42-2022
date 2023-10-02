#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "bureaucrat"

class Form {
    public:
        Form();
        Form(const Form& other);
        Form operator=(const Form& other);
        ~Form();

        // Exception clases
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
        int getGradeSigned() const;
        int getGradeExecuted() const;

        void beSigned(const Bureaucrat& b); // this function changes the form status to signed if the grade is high enough

    private:
        const std::string m_name;
        bool m_is_signed;
        const int m_grade_signed;
        const int m_grade_executed;
};

std::ostream& operator<<(std::ostream &stream, const Form& other);

#endif
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

// Fordward Decleration
class Form; // You can do this when you only have pointers and references to a type, but you don't actually use any of the objects methods or properties.

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // exception classes
        class GradeTooHighException : public std::exception {
               public:
                    const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
               public:
                    const char* what() const throw();
        };

        std::string getName() const;
        int getGrade() const;

        void setGrade(int grade);

        void incrementGrade();
        void decrementGrade();

        void signForm(Form& form); 
    private:
        const std::string m_name;
        int m_grade;
};

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& other);

#endif